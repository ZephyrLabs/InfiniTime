#include "calendar.h"
#include "../DisplayApp.h"
#include "../LittleVgl.h"

using namespace Pinetime::Applications::Screens;

static void event_handler(lv_obj_t* obj, lv_event_t event) {
  calendar *screen = static_cast<calendar *>(obj->user_data);
  screen->OnCalendarTouchEvent(obj, event);
}

calendar::calendar(Pinetime::Applications::DisplayApp* app, Pinetime::Components::LittleVgl& lvgl) : Screen(app), lvgl{lvgl} {
  app->SetTouchMode(DisplayApp::TouchModes::Polling);
  
  cal = lv_calendar_create(lv_scr_act(), NULL);
  lv_obj_set_size(cal, LV_HOR_RES_MAX, LV_VER_RES_MAX);
  lv_obj_align(cal, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_event_cb(cal, event_handler);

  /*Make the date number smaller to be sure they fit into their area*/
  lv_obj_set_style_local_text_font(cal, LV_CALENDAR_PART_DATE, LV_STATE_DEFAULT, lv_theme_get_font_small());
  lv_obj_set_style_local_text_color(cal, LV_CALENDAR_PART_HEADER, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_color(cal, LV_CALENDAR_PART_DAY_NAMES, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_color(cal, LV_CALENDAR_PART_DATE, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_color(cal, LV_CALENDAR_PART_DATE, LV_STATE_FOCUSED, LV_COLOR_RED);
  lv_obj_set_style_local_text_color(cal, LV_CALENDAR_PART_DATE, LV_STATE_CHECKED, LV_COLOR_BLUE);

  /*Set today's date*/
  today.year = 2021;
  today.month = 2;
  today.day = 12;

  lv_calendar_set_today_date(cal, &today);
  lv_calendar_set_showed_date(cal, &today);
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

bool calendar::OnCalendarTouchEvent(lv_obj_t* obj, lv_event_t event) {
  if(event == LV_EVENT_VALUE_CHANGED) {
    lv_calendar_date_t * date = lv_calendar_get_pressed_date(obj);
    if(date) {
      lv_calendar_set_highlighted_dates(cal, date, 1);
    }
  }
  return true;
}

