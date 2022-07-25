#include "page1.h"

#include <stdio.h>

void page_page1_onLoad(lv_obj_t *page)
{
  printf("lifecycle: page1 onLoad\n");
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello page1");
}

void page_page1_unLoad(lv_obj_t *page)
{
  printf("lifecycle: page1 unLoad\n");
}