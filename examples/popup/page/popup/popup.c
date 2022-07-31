#include "popup.h"

#include <stdio.h>

#include "CLOSE.c"

void page_popup_onLoad(lv_obj_t *page)
{
  printf("lifecycle: popup onLoad\n");
  lv_obj_set_style_bg_color(page, lv_color_make(150, 199, 4), LV_STATE_DEFAULT);
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello popup page");
  lv_obj_center(label);
  lv_obj_t *close = lv_img_create(page);
  lv_img_set_src(close, &CLOSE);
  lv_obj_set_x(close, 216);
  lv_obj_set_y(close, 5);
}

void page_popup_unLoad(lv_obj_t *page)
{
  printf("lifecycle: popup unLoad\n");
}