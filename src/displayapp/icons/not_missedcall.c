#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_NOT_MISSEDCALL
#define LV_ATTRIBUTE_IMG_NOT_MISSEDCALL
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_NOT_MISSEDCALL uint8_t not_missedcall_map[] = {
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 0*/
  0x05, 0x21, 0x15, 0xff, 	/*Color of index 1*/
  0x0a, 0x2d, 0x1f, 0xff, 	/*Color of index 2*/
  0x0d, 0x45, 0x2e, 0xff, 	/*Color of index 3*/
  0x49, 0x47, 0x43, 0xff, 	/*Color of index 4*/
  0x19, 0x6b, 0x49, 0xff, 	/*Color of index 5*/
  0x76, 0x73, 0x6f, 0xff, 	/*Color of index 6*/
  0x19, 0x83, 0x59, 0xff, 	/*Color of index 7*/
  0x1d, 0x9f, 0x67, 0xff, 	/*Color of index 8*/
  0x26, 0xb5, 0x7a, 0xff, 	/*Color of index 9*/
  0xaf, 0xa8, 0xa4, 0xff, 	/*Color of index 10*/
  0x25, 0xc4, 0x88, 0xff, 	/*Color of index 11*/
  0x2d, 0xd5, 0x92, 0xff, 	/*Color of index 12*/
  0xd1, 0xc7, 0xbf, 0xff, 	/*Color of index 13*/
  0xe5, 0xdc, 0xd5, 0xff, 	/*Color of index 14*/
  0xf0, 0xe7, 0xe0, 0xff, 	/*Color of index 15*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xff, 0xee, 0xee, 0xee, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xfe, 0xee, 0xee, 0xee, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xaa, 0xde, 0xee, 0xee, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xea, 0xde, 0xee, 0xee, 
  0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xfa, 0xde, 0xee, 0xee, 
  0x00, 0x01, 0x89, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xda, 0xae, 0xee, 0xee, 
  0x00, 0x18, 0x99, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xff, 0xee, 0xee, 0xee, 
  0x01, 0x99, 0x99, 0x99, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xff, 0xee, 0xee, 0xee, 
  0x09, 0xcb, 0x99, 0x99, 0x93, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xff, 0xee, 0xee, 0xee, 
  0x5c, 0xcc, 0xb9, 0x99, 0x99, 0x30, 0x00, 0x00, 0x00, 0x06, 0xaa, 0xef, 0xfa, 0xdd, 0xdd, 0xdd, 
  0x8c, 0xcc, 0xcb, 0x99, 0x99, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf, 0x40, 0x00, 0x00, 0x00, 
  0xbc, 0xcc, 0xcc, 0xb9, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00, 
  0xbc, 0xcc, 0xcc, 0xcb, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x9c, 0xcc, 0xcc, 0xcc, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x5c, 0xcc, 0xcc, 0xcc, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x09, 0xcc, 0xcc, 0xcc, 0xcc, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x02, 0xbc, 0xcc, 0xcc, 0xcc, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x2b, 0xcc, 0xcc, 0xcc, 0xcc, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0xbc, 0xcc, 0xcc, 0xcc, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x2b, 0xcc, 0xcc, 0xcb, 0xbb, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0xbc, 0xcc, 0xbb, 0xbb, 0xb8, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x2b, 0xcb, 0xbb, 0xbb, 0xbb, 0x80, 0x03, 0x88, 0x30, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x02, 0xbb, 0xbb, 0xbb, 0xbb, 0xb8, 0x38, 0x88, 0x83, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3b, 0xbb, 0xbb, 0xbb, 0xbb, 0xb8, 0x88, 0x88, 0x30, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x03, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0x88, 0x88, 0x83, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0xbb, 0xbb, 0xbb, 0xbb, 0xb8, 0x88, 0x88, 0x30, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0x88, 0x87, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0xbb, 0xbb, 0xbb, 0xbb, 0xb8, 0x71, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xbb, 0xbb, 0xbb, 0xbb, 0xb9, 0x10, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0xbb, 0xbb, 0xbb, 0xb2, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xbb, 0x97, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t not_missedcall = {
  .header.always_zero = 0,
  .header.w = 32,
  .header.h = 32,
  .data_size = 576,
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .data = not_missedcall_map,
};
