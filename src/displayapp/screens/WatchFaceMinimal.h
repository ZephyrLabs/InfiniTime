#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <chrono>
#include <cstdint>
#include <memory>
#include "Screen.h"
#include "ScreenList.h"
#include "components/datetime/DateTimeController.h"
#include "components/battery/BatteryController.h"
#include "components/ble/BleController.h"
#include "components/ble/NotificationManager.h"

namespace Pinetime {
  namespace Controllers {
    class Settings;
    class Battery;
    class Ble;
    class NotificationManager;
  }
  namespace Applications {
    namespace Screens {

      class WatchFaceMinimal : public Screen {
        public:
          WatchFaceMinimal(DisplayApp* app,
                  Controllers::DateTime& dateTimeController,
                  Controllers::Battery& batteryController,
                  Controllers::Ble& bleController,
                  Controllers::NotificationManager& notificatioManager,
                  Controllers::Settings &settingsController);
          
          ~WatchFaceMinimal() override;

          bool Refresh() override;

        private:
          uint8_t sHour, sMinute, sSecond;
          Pinetime::Controllers::DateTime::Months month;
          uint8_t day;
          Pinetime::Controllers::DateTime::Days dayOfWeek;

          uint8_t hour;
          uint8_t minute;
          uint8_t second;

          Pinetime::Controllers::DateTime::Months currentMonth = Pinetime::Controllers::DateTime::Months::Unknown;
          Pinetime::Controllers::DateTime::Days currentDayOfWeek = Pinetime::Controllers::DateTime::Days::Unknown;
          uint8_t currentDay = 0;

          DirtyValue<float> batteryPercentRemaining  {0};
          DirtyValue<bool> bleState {false};
          DirtyValue<std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds>> currentDateTime;
          DirtyValue<uint32_t> stepCount  {0};
          DirtyValue<uint8_t> heartbeat  {0};
          DirtyValue<bool> notificationState {false};
          
          lv_style_t sep_style;
          lv_style_t not_style;
          lv_style_t hour_style;
          lv_style_t min_style;
          lv_style_t dateyear_style;

          lv_obj_t* label_time;
          lv_obj_t* label_time_min;
          lv_obj_t* label_time_sep;
          lv_obj_t* label_date;
          lv_obj_t* backgroundLabel;
          lv_obj_t* notificationIcon;

          Controllers::DateTime& dateTimeController;
          Controllers::Battery& batteryController;
          Controllers::Ble& bleController;
          Controllers::NotificationManager& notificatioManager;
          Controllers::Settings& settingsController;
      };
    }
  }
}