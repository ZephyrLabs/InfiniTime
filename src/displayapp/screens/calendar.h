#pragma once

#include <lvgl/lvgl.h>
#include <cstdint>
#include "Screen.h"

namespace Pinetime {
  namespace Components {
    class LittleVgl;
  }
  namespace Applications {
    namespace Screens {

      class calendar : public Screen {
      public:
        calendar(DisplayApp* app, Pinetime::Components::LittleVgl& lvgl);

        ~calendar() override;

        bool Refresh() override;

        bool OnButtonPushed() override;

        bool OnTouchEvent(TouchEvents event) override;

        bool OnTouchEvent(uint16_t x, uint16_t y) override;

        bool OnCalendarTouchEvent(lv_obj_t* obj, lv_event_t event);
      private:
        Pinetime::Components::LittleVgl& lvgl;
        bool running = true;
        lv_obj_t* cal;
        lv_obj_t* txtTrackDuration;
        lv_obj_t* container1;
        lv_calendar_date_t today;
      };
    }
  }
}
