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
  0x18, 0x0e, 0x05, 0xff, 	/*Color of index 1*/
  0x08, 0x16, 0x0a, 0xff, 	/*Color of index 2*/
  0x34, 0x20, 0x04, 0xff, 	/*Color of index 3*/
  0x10, 0x29, 0x10, 0xff, 	/*Color of index 4*/
  0x19, 0x38, 0x17, 0xff, 	/*Color of index 5*/
  0x59, 0x37, 0x0b, 0xff, 	/*Color of index 6*/
  0x74, 0x47, 0x0e, 0xff, 	/*Color of index 7*/
  0x23, 0x4c, 0x21, 0xff, 	/*Color of index 8*/
  0x97, 0x5b, 0x11, 0xff, 	/*Color of index 9*/
  0xaf, 0x6a, 0x17, 0xff, 	/*Color of index 10*/
  0x32, 0x70, 0x2f, 0xff, 	/*Color of index 11*/
  0xcc, 0x7e, 0x1a, 0xff, 	/*Color of index 12*/
  0x3d, 0x8d, 0x3d, 0xff, 	/*Color of index 13*/
  0xf3, 0x96, 0x10, 0xff, 	/*Color of index 14*/
  0x4d, 0xad, 0x4a, 0xff, 	/*Color of index 15*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x16, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x48, 0x88, 0x88, 0x88, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 
  0xce, 0xee, 0xee, 0xee, 0xee, 0x60, 0x00, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2d, 0xfd, 
  0xee, 0xee, 0xee, 0xee, 0xee, 0x70, 0x00, 0x04, 0xff, 0xff, 0xff, 0xff, 0xff, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0xdf, 0xfd, 
  0xee, 0xee, 0xee, 0xee, 0xee, 0x90, 0x00, 0x04, 0xff, 0xff, 0xb4, 0x44, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0xff, 0xd0, 
  0xce, 0xee, 0xee, 0xee, 0xee, 0x90, 0x00, 0x04, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xff, 0xfb, 0x00, 
  0xce, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x04, 0xff, 0xbf, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x02, 0xdf, 0xff, 0x50, 0x00, 
  0x9e, 0xee, 0xee, 0xee, 0xee, 0xe0, 0x00, 0x04, 0xff, 0x54, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x4d, 0xff, 0xd4, 0x00, 0x00, 
  0x7e, 0xee, 0xee, 0xee, 0xee, 0xe1, 0x00, 0x04, 0xff, 0x50, 0x4f, 0xff, 0x80, 0x00, 0x00, 0x05, 0xff, 0xfd, 0x20, 0x00, 0x00, 
  0x6e, 0xee, 0xee, 0xee, 0xee, 0xe6, 0x00, 0x04, 0xff, 0x50, 0x04, 0xff, 0xf8, 0x00, 0x00, 0x8f, 0xff, 0xb0, 0x00, 0x00, 0x00, 
  0x3e, 0xee, 0xee, 0xee, 0xee, 0xea, 0x00, 0x04, 0xff, 0x50, 0x00, 0x4f, 0xff, 0x80, 0x2d, 0xff, 0xf5, 0x00, 0x00, 0x00, 0x00, 
  0x0c, 0xee, 0xee, 0xee, 0xee, 0xee, 0x00, 0x00, 0xff, 0x20, 0x00, 0x04, 0xff, 0xfb, 0xdf, 0xfd, 0x40, 0x00, 0x00, 0x00, 0x00, 
  0x09, 0xee, 0xee, 0xee, 0xee, 0xee, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0xff, 0xff, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x06, 0xee, 0xee, 0xee, 0xee, 0xee, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xff, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xee, 0xee, 0xee, 0xee, 0xee, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4b, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x9e, 0xee, 0xee, 0xee, 0xec, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x6e, 0xee, 0xee, 0xec, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x0c, 0xee, 0xee, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x06, 0xee, 0xee, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xce, 0xee, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x3e, 0xee, 0xec, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0a, 0xee, 0xee, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xee, 0xee, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x6e, 0xee, 0xee, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x09, 0xee, 0xee, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xce, 0xee, 0xee, 0x60, 0x00, 0x00, 0x00, 0x07, 0x93, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x1c, 0xee, 0xee, 0xe6, 0x00, 0x00, 0x00, 0x6e, 0xee, 0xc7, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x01, 0xce, 0xee, 0xee, 0x90, 0x00, 0x00, 0xce, 0xee, 0xee, 0xec, 0x97, 0x63, 0x31, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xee, 0xee, 0xec, 0x30, 0x06, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xce, 0xee, 0xee, 0xe7, 0x0a, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xee, 0xee, 0xee, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9e, 0xee, 0xee, 0xee, 0xee, 0xee, 0xa0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x9c, 0xee, 0xee, 0xee, 0x90, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33, 0x66, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t not_missedcall = {
  .header.always_zero = 0,
  .header.w = 42,
  .header.h = 42,
  .data_size = 946,
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .data = not_missedcall_map,
};

