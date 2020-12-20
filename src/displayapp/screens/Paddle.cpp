#include "Paddle.h"
#include "../DisplayApp.h"
#include "../LittleVgl.h"

using namespace Pinetime::Applications::Screens;
extern lv_font_t jetbrains_mono_extrabold_compressed;
extern lv_font_t jetbrains_mono_bold_20;

namespace{
const uint8_t paddle_map[] = {
  0xfc, 0xfe, 0xfc, 0xff, 	/*Color of index 0*/
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 1*/

  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
};

const uint8_t ball_map[] = {
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 
  0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 
  0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 
  0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
  0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 0x6f, 0xed, 
};
}

Paddle::Paddle(Pinetime::Applications::DisplayApp* app, Pinetime::Components::LittleVgl& lvgl) : Screen(app), lvgl{lvgl} {
  app->SetTouchMode(DisplayApp::TouchModes::Polling);
	
  points = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(points, "0");	
  lv_obj_align(points, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 0);
	
  paddle.header.always_zero = 0;
  paddle.header.w = 4;
  paddle.header.h = 60;
  paddle.data_size = 68;
  paddle.header.cf = LV_IMG_CF_INDEXED_1BIT;
  paddle.data = paddle_map;  
  paddle_image = lv_img_create(lv_scr_act(), nullptr);
  lv_img_set_src(paddle_image, &paddle);
  
  ball.header.always_zero = 0;
  ball.header.w = 24;
  ball.header.h = 24;
  ball.data_size = 24 * 24 * LV_COLOR_SIZE / 8;
  ball.header.cf = LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED;
  ball.data = ball_map;  
  ball_image = lv_img_create(lv_scr_act(), nullptr);
  lv_img_set_src(ball_image, &ball);
}

Paddle::~Paddle() {
  // Reset the touchmode
  app->SetTouchMode(DisplayApp::TouchModes::Gestures);
  lv_obj_clean(lv_scr_act());
}

bool Paddle::Refresh() {
  if((counter++ % 5) == 0){
    counter = 0;	
    
    ballX += dx;
    ballY += dy;	    
	  
    lv_obj_set_pos(ball_image, ballX, ballY);
  
    //checks if it has touched the sides (floor and ceiling)	  
    if(ballY <= 0 || ballY >= 215){
      dy *= -1;
    }
  
    //checks if it has touched the side (left side)  
    if(ballX >= 215){
      dx *= -1; 
    }
  
    //checks if it is in the position of the paddle	  
    if(ballY <= (paddleBottomY + 16) && ballY >= (paddleTopY - 8)){ 
      if(ballX >= 0 && ballX < 5){    
          lv_obj_set_pos(ball_image, 5, ballY);
          dx *= -1;   
          score++;
        } 
    }	
	  
    //checks if it has gone behind the paddle
    else if(ballX <= -40){
      ballX = 107;
      ballY = 107; 
      score = 0;	    
    } 
    sprintf(scoreStr, "%d", score);	
    lv_label_set_text(points, scoreStr);	  
  }      
  return running;
}

bool Paddle::OnButtonPushed() {
  running = false;
  return true;
}

bool Paddle::OnTouchEvent(Pinetime::Applications::TouchEvents event) { 
  return true; 
}

bool Paddle::OnTouchEvent(uint16_t x, uint16_t y) {
  lv_obj_set_pos(paddle_image, 0, y - 30);		// sets the center paddle pos. (30px offset) with the the y_coordinate of the finger and defaults the x_coordinate to 0
  paddleTopY = y - 30;					// refreshes the upper extreme of the paddle
  paddleBottomY = y + 30;					// refreshes the lower extreme of the paddle
  
  return true;
}
