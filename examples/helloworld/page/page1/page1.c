#include "page1.h"

#include <stdio.h>

void page_page1_onLoad(lv_obj_t *page)
{
  printf("lifecycle: page1 onLoad\n");
  lv_obj_set_style_bg_color(page, lv_color_make(237, 175, 5), LV_STATE_DEFAULT);
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello page1");
  lv_obj_center(label);
}

void page_page1_unLoad(lv_obj_t *page)
{
  printf("lifecycle: page1 unLoad\n");
}