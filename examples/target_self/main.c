#include "pm.h"
#include <stdio.h>

#include "page/page1/page1.h"
#include "page/page2/page2.h"

lv_pm_open_options_t options = {
  .animation = LV_PM_ANIMA_SLIDE
};

lv_pm_open_options_t options_self = {
  .animation = LV_PM_ANIMA_SLIDE,
  .target = LV_PM_TARGET_SELF
};

uint8_t page_id = 1;
void timer_cb(lv_timer_t *timer)
{
  printf("open page: %d\n", page_id);
  lv_pm_open_page(page_id, &options_self);

  if (page_id == 1) {
    page_id = 0;
  } else {
    page_id = 1;
  }
}

void app_start()
{
  lv_pm_init();

  lv_pm_page_t *page1 = lv_pm_create_page(0);
  page1->onLoad = page_page1_onLoad;
  page1->unLoad = page_page1_unLoad;

  lv_pm_page_t *page2 = lv_pm_create_page(1);
  page2->onLoad = page_page2_onLoad;
  page2->unLoad = page_page2_unLoad;

  printf("start\n");
  lv_pm_open_page(0, &options);
  lv_timer_create(timer_cb, 5000, NULL);
}
