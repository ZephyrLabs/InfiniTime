#include "SettingCustomize.h"
#include <lvgl/lvgl.h>
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Symbols.h"

using namespace Pinetime::Applications::Screens;

namespace {
  static void event_handler(lv_obj_t * obj, lv_event_t event) {
    SettingCustomize* screen = static_cast<SettingCustomize *>(obj->user_data);
    screen->UpdateSelected(obj, event);
  }
}

SettingCustomize::SettingCustomize(
  Pinetime::Applications::DisplayApp *app, Pinetime::Controllers::Settings &settingsController) :
  Screen(app),
  settingsController{settingsController}
{
  static lv_point_t line_points[] = { {0, 0}, {0, 40} };

  static lv_style_t style_line;
  lv_style_init(&style_line);
  lv_style_set_line_width(&style_line, LV_STATE_DEFAULT, 40);
  lv_style_set_line_rounded(&style_line, LV_STATE_DEFAULT, true);
  
  colorLine = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_points(colorLine, line_points, 2);
  lv_obj_add_style(colorLine, LV_LINE_PART_MAIN, &style_line);
  lv_obj_align(colorLine, NULL, LV_ALIGN_IN_LEFT_MID, 40, 70);

  lv_obj_t * title = lv_label_create(lv_scr_act(), NULL);  
  lv_label_set_text_static(title,"UI color");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 15, 5);

  lv_obj_t * icon = lv_label_create(lv_scr_act(), NULL);
  lv_obj_set_style_local_text_color(icon, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_ORANGE);
  lv_label_set_text_static(icon, Symbols::paintbrush);
  lv_label_set_align(icon, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(icon, title, LV_ALIGN_OUT_LEFT_MID, -10, 0);

  redSlider = lv_slider_create(lv_scr_act(), NULL);
  redSlider->user_data = this;
  lv_slider_set_range(redSlider, 0, 255);
  lv_obj_set_style_local_bg_color(redSlider, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, LV_COLOR_RED);
  lv_obj_align(redSlider, NULL, LV_ALIGN_IN_TOP_MID, 0, 50);
  lv_obj_set_event_cb(redSlider, event_handler);

  greenSlider = lv_slider_create(lv_scr_act(), NULL);
  greenSlider->user_data = this;
  lv_slider_set_range(greenSlider, 0, 255);
  lv_obj_set_style_local_bg_color(greenSlider, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, LV_COLOR_GREEN);
  lv_obj_align(greenSlider, redSlider, LV_ALIGN_IN_TOP_MID, 0, 40);
  lv_obj_set_event_cb(greenSlider, event_handler);

  blueSlider = lv_slider_create(lv_scr_act(), NULL);
  blueSlider->user_data = this;
  lv_slider_set_range(blueSlider, 0, 255);
  lv_obj_set_style_local_bg_color(blueSlider, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, LV_COLOR_BLUE);
  lv_obj_align(blueSlider, greenSlider, LV_ALIGN_IN_TOP_MID, 0, 40);
  lv_obj_set_event_cb(blueSlider, event_handler);

  btnMinus = lv_btn_create(lv_scr_act(), NULL);
  btnMinus->user_data = this;
  lv_obj_set_size(btnMinus, 60, 60);
  lv_obj_set_event_cb(btnMinus, event_handler);
  lv_obj_align(btnMinus, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, 0);
  lv_obj_set_style_local_value_str(btnMinus, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, "<");

  btnPlus = lv_btn_create(lv_scr_act(), NULL);
  btnPlus->user_data = this;
  lv_obj_set_size(btnPlus, 60, 60);
  lv_obj_align(btnPlus, btnMinus, LV_ALIGN_IN_BOTTOM_MID, 80, 0);
  lv_obj_set_style_local_value_str(btnPlus, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, ">");
  lv_obj_set_event_cb(btnPlus, event_handler);

  objSelected = lv_label_create(lv_scr_act(), NULL);  
  lv_label_set_text_static(objSelected, objList[objNum]);
  lv_obj_align(objSelected, lv_scr_act(), LV_ALIGN_CENTER, 0, 35);
}

SettingCustomize::~SettingCustomize() {
  lv_obj_clean(lv_scr_act());
  settingsController.SaveSettings();
}

bool SettingCustomize::Refresh() {
  return running;
}


void SettingCustomize::UpdateSelected(lv_obj_t *object, lv_event_t event) {
  
  if(object == redSlider || object == greenSlider || object == blueSlider){
    if(object == redSlider && (event == LV_EVENT_VALUE_CHANGED)) {
      redValue = lv_slider_get_value(redSlider);
      }
    
    if(object == greenSlider && (event == LV_EVENT_VALUE_CHANGED)) {
      greenValue = lv_slider_get_value(greenSlider);
      }
    
    if(object == blueSlider  && (event == LV_EVENT_VALUE_CHANGED)) {
      blueValue = lv_slider_get_value(blueSlider);
      }

    objColor[objNum] = lv_color_make(redValue, greenValue, blueValue);
  }

  if(object == btnMinus || object == btnPlus){
    if(object == btnMinus && (event == LV_EVENT_CLICKED)){
      if(objNum > numMin)objNum--;
    }

    if(object == btnPlus && (event == LV_EVENT_CLICKED)){
      if(objNum < numMax)objNum++;
    }

    lv_label_set_text_static(objSelected, objList[objNum]);

    lv_slider_set_value(redSlider, objColor[objNum].ch.red * 9, LV_ANIM_ON);
    lv_slider_set_value(greenSlider, (objColor[objNum].ch.green_h) * 38, LV_ANIM_ON);
    lv_slider_set_value(blueSlider, objColor[objNum].ch.blue * 9, LV_ANIM_ON);
  }


  lv_obj_set_style_local_line_color(colorLine, LV_LINE_PART_MAIN, LV_STATE_DEFAULT, objColor[objNum]);
}
