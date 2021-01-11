#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <chrono>
#include <cstdint>
#include <memory>
#include "Screen.h"
#include "components/datetime/DateTimeController.h"

namespace Pinetime {
  namespace Controllers {
    class Battery;
    class Ble;
    class NotificationManager;
  }

  namespace Applications {
    namespace Screens {

      template <class T>
      class DirtyValue {
        public:
          explicit DirtyValue(T v) { value = v; }
          explicit DirtyValue(T& v) { value = v; }
          bool IsUpdated() const { return isUpdated; }
          T& Get() { this->isUpdated = false; return value; }

          DirtyValue& operator=(const T& other) {
            if (this->value != other) {
              this->value = other;
              this->isUpdated = true;
            }
            return *this;
          }
        private:
          T value;
          bool isUpdated = true;
      };
      class Clock : public Screen {
        public:
          Clock(DisplayApp* app,
                  Controllers::DateTime& dateTimeController,
                  Controllers::Battery& batteryController,
                  Controllers::Ble& bleController,
                  Controllers::NotificationManager& notificatioManager);
          ~Clock() override;

          bool Refresh() override;
          bool OnButtonPushed() override;
          bool OnTouchEvent(TouchEvents event) override;
        
          void OnObjectEvent(lv_obj_t *pObj, lv_event_t i);
        private:

          void start();
          void stop();
          void reset();
          float getCurrentTime();

          float currentTime = 0.0f;
          bool stopWatchRunning = false;
        
          std::chrono::system_clock::time_point startTime;

          static const char* MonthToString(Pinetime::Controllers::DateTime::Months month);
          static const char* DayOfWeekToString(Pinetime::Controllers::DateTime::Days dayOfWeek);

          char displayedChar[5];

          uint16_t currentYear = 1970;
          Pinetime::Controllers::DateTime::Months currentMonth = Pinetime::Controllers::DateTime::Months::Unknown;
          Pinetime::Controllers::DateTime::Days currentDayOfWeek = Pinetime::Controllers::DateTime::Days::Unknown;
          uint8_t currentDay = 0;

          DirtyValue<float> batteryPercentRemaining  {0};
          DirtyValue<bool> bleState {false};
          DirtyValue<std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>> currentDateTime;
          DirtyValue<uint32_t> stepCount  {0};
          DirtyValue<uint8_t> heartbeat  {0};
          DirtyValue<bool> notificationState {false};

          lv_obj_t* label_time;
          lv_obj_t* label_date;
          lv_obj_t* backgroundLabel;
          lv_obj_t* batteryIcon;
          lv_obj_t* bleIcon;
          lv_obj_t* batteryPlug;
          lv_obj_t* heartbeatIcon;
          lv_obj_t* heartbeatValue;
          lv_obj_t* heartbeatBpm;
          lv_obj_t* stepIcon;
          lv_obj_t* stepValue;
          lv_obj_t* notificationIcon;

          lv_obj_t* img_src;
          lv_obj_t* hour_hand;
          lv_obj_t* minute_hand;
          lv_obj_t* second_hand;
          lv_obj_t* chrono_second_hand;
          lv_obj_t* chrono_minute_hand;
          lv_obj_t* img_src_globe;

          int hour_offset = 0;

          int hour_utc = 0;

          int counter;  
            
          int chrono_second = 0;
          int chrono_minute = 0;

          int hour_angle = 0;
          int minute_angle = 0;
          int second_angle = 0;
          int chrono_second_angle = 0;
          int chrono_minute_angle = 0;

          double hour_sin = 0;
          double hour_cos = 1;

          double minute_sin = 0;
          double minute_cos = 1;

          double second_sin = 0;
          double second_cos = 1;

          double chrono_second_sin = 0;
          double chrono_second_cos = 1;

          double chrono_minute_sin = 0;
          double chrono_minute_cos = 1;

          int hour_x = 0;
          int hour_y = 57;

          int minute_x = 0;
          int minute_y = 77;

          int second_x = 0;
          int second_y = 97;

          int chrono_second_x = 0;
          int chrono_second_y = 25;

          int chrono_minute_x = 0;
          int chrono_minute_y = 25;


          int hour_len = 57;
          int minute_len = 77;
          int second_len = 97;
          int chrono_second_len = 25;
          int chrono_minute_len = 25;

          static lv_point_t hour_points[] = { {120, 120}, {hour_x, hour_y} };
          static lv_point_t minute_points[] = { {120, 120}, {minute_x, minute_y} };
          static lv_point_t second_points[] = { {120, 120}, {second_x, second_y} };
          static lv_point_t chrono_second_points[] = { {180, 120}, {chrono_second_x, chrono_second_y} };
          static lv_point_t chrono_minute_points[] = { {60, 120}, {chrono_minute_x, chrono_minute_y} };

          Controllers::DateTime& dateTimeController;
          Controllers::Battery& batteryController;
          Controllers::Ble& bleController;
          Controllers::NotificationManager& notificatioManager;

          bool running = true;

      };
    }
  }
}
