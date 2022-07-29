#include "page2.h"

#include <stdio.h>

void page_page2_onLoad(lv_obj_t *page)
{
  printf("lifecycle: page2 onLoad\n");
  lv_obj_set_style_bg_color(page, lv_color_make(150, 199, 4), LV_STATE_DEFAULT);
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello page2");
  lv_obj_center(label);
}

void page_page2_unLoad(lv_obj_t *page)
{
  printf("lifecycle: page2 unLoad\n");
}