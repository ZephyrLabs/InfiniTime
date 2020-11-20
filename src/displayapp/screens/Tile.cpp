#include <libs/lvgl/src/lv_core/lv_obj.h>
#include <libs/lvgl/src/lv_font/lv_font.h>
#include <libs/lvgl/lvgl.h>

#include "Tile.h"
#include "displayapp/DisplayApp.h"
#include "Symbols.h"
#include "../../Version.h"

using namespace Pinetime::Applications::Screens;

typedef struct {
    lv_btnm_ext_t imgbtn;       
    int appNumber;          
}temp_btnm_ext_t;

static void event_handler(lv_obj_t * obj, lv_event_t event) {
  temp_btnm_ext_t * ext = static_cast<temp_btnm_ext_t *>(lv_obj_get_ext_attr(obj));
  Tile* screen = static_cast<Tile *>(obj->user_data);

  screen->OnObjectEvent(obj, event, ext->appNumber);

}

static std::array<std::array<lv_coord_t, 2>, 4> iconPos = {{{-55, -50}, {55, -50}, {-55, 60}, {55, 60}}};

Tile::Tile(DisplayApp* app, Controllers::DateTime& dateTimeController, std::array<Applications, 4>& applications) : 
    Screen(app),
    dateTimeController{dateTimeController} 
{

  uint8_t hours = dateTimeController.Hours();
  uint8_t minutes = dateTimeController.Minutes();
  oldHours = hours;
  oldMinutes = minutes;

  // Time
  lv_obj_t* label_time = lv_label_create(lv_scr_act(), NULL);  
  lv_label_set_text_fmt(label_time,  "%02i:%02i", hours, minutes);      
  lv_label_set_align( label_time, LV_LABEL_ALIGN_CENTER );    
  lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 0);

  for(int i = 0, appIndex = 0; i < 4; i++) {
    if ( applications[i].application == Apps::None)
      appIndex++;
    else {
      iconsApps[appIndex] = lv_imgbtn_create(lv_scr_act(), NULL);
      lv_imgbtn_set_src(iconsApps[appIndex], LV_BTN_STATE_REL, applications[i].icon);
      lv_imgbtn_set_src(iconsApps[appIndex], LV_BTN_STATE_PR, applications[i].icon);
      lv_obj_align(iconsApps[appIndex], NULL, LV_ALIGN_CENTER, iconPos[i][0], iconPos[i][1]);
      lv_obj_allocate_ext_attr(iconsApps[appIndex], sizeof(temp_btnm_ext_t));
      iconsApps[appIndex]->user_data = this;
      lv_obj_set_event_cb(iconsApps[appIndex], event_handler);
      temp_btnm_ext_t * ext = static_cast<temp_btnm_ext_t *>(lv_obj_get_ext_attr(iconsApps[appIndex]));
      ext->appNumber = appIndex;

      apps[appIndex] = applications[i].application;
      appIndex++;
    }
  }

  backgroundLabel = lv_label_create(lv_scr_act(), nullptr);
  backgroundLabel->user_data = this;
  lv_label_set_long_mode(backgroundLabel, LV_LABEL_LONG_CROP);
  lv_obj_set_size(backgroundLabel, 240, 240);
  lv_obj_set_pos(backgroundLabel, 0, 0);
  lv_label_set_text(backgroundLabel, "");

}

Tile::~Tile() {
  lv_obj_clean(lv_scr_act());
}

bool Tile::Refresh() {

  uint8_t hours = dateTimeController.Hours();
  uint8_t minutes = dateTimeController.Minutes();

  if(oldHours != hours || oldMinutes != minutes) {
    lv_label_set_text_fmt(label_time,  "%02i:%02i", hours, minutes);
    oldHours = hours;
    oldMinutes = minutes;
  }

  return running;
}

void Tile::OnObjectEvent(lv_obj_t *obj, lv_event_t event, uint32_t buttonId) {
  if(event == LV_EVENT_CLICKED) {
    app->StartApp(apps[buttonId]);
    running = false;
  }
}

bool Tile::OnButtonPushed() {
  app->StartApp(Apps::Clock);
  running = false;
  return true;
}


