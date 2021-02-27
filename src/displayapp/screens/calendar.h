#pragma once

#include <lvgl/lvgl.h>
#include <cstdint>
#include "Screen.h"

namespace Pinetime {
  namespace Components {
    class DateTime;
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

        bool OnCalendarTouchEvent(lv_obj_t* obj, lv_event_t event);
      private:
        Pinetime::Components::LittleVgl& lvgl;
        Pinetime::Controllers::DateTime& dateTimeController,
        lv_obj_t* cal;
        lv_calendar_date_t today;
        lv_calendar_date_t viewday;
        
        bool running = true;
      };
    }
  }
}
