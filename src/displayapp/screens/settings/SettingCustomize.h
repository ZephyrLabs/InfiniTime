#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingCustomize : public Screen{
        public:
          SettingCustomize(DisplayApp* app, Pinetime::Controllers::Settings &settingsController);
          ~SettingCustomize() override;

          bool Refresh() override;
          void UpdateSelected(lv_obj_t *object, lv_event_t event);
         
        private:      
        
          Controllers::Settings& settingsController;
                    
          lv_obj_t* redSlider;
          lv_obj_t* greenSlider;
          lv_obj_t* blueSlider;
          lv_obj_t* colorLine;
          lv_obj_t* btnPlus;
          lv_obj_t* btnMinus;
          lv_obj_t* objSelected;

          int objNum = 0;
          int numMin = 0;
          int numMax = 3;

          int redValue = 0;
          int greenValue = 0;
          int blueValue = 0;

          char* objList[4] = {"txt",
                            "subtxt",
                            "btn",
                            "btntxt"
                            };

          lv_color_t objColor[4];
      };
    }
  }
}
