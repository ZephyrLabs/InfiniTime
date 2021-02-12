#include "calendar.h"
#include "../DisplayApp.h"
#include "../LittleVgl.h"

using namespace Pinetime::Applications::Screens;

static void event_handler(lv_obj_t* obj, lv_event_t event)
{
}

calendar::calendar(Pinetime::Applications::DisplayApp* app, Pinetime::Components::LittleVgl& lvgl) : Screen(app), lvgl{lvgl} {
  app->SetTouchMode(DisplayApp::TouchModes::Polling);

  lv_obj_t  * calendar = lv_calendar_create(lv_scr_act(), NULL);
  lv_obj_set_size(calendar, 235, 235);
  lv_obj_align(calendar, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_event_cb(calendar, event_handler);

  /*Make the date number smaller to be sure they fit into their area*/
  /*lv_obj_set_style_local_text_font(calendar, LV_CALENDAR_PART_DATE, LV_STATE_DEFAULT, lv_theme_get_font_small());*/


  /*Set today's date*/
  lv_calendar_date_t today;
  today.year = 2021;
  today.month = 2;
  today.day = 11;

  lv_calendar_set_today_date(calendar, &today);
  lv_calendar_set_showed_date(calendar, &today);

}

calendar::~calendar() {
  // Reset the touchmode
  app->SetTouchMode(DisplayApp::TouchModes::Gestures);
  lv_obj_clean(lv_scr_act());
}

bool calendar::Refresh() {
  return running;
}

bool calendar::OnButtonPushed() {
  running = false;
  return true;
}

bool calendar::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  return true;
}

bool calendar::OnTouchEvent(uint16_t x, uint16_t y) {
  return true;
}

