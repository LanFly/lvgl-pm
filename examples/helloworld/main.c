#include "pm.h"

#include "page/page1/page1.h"
#include "page/page2/page2.h"

void app_start()
{
  lv_pm_init();

  lv_pm_page_t *page1 = lv_pm_create_page(0);
  page1->onLoad = page_page1_onLoad;
  page1->unLoad = page_page1_unLoad;

  lv_pm_page_t *page2 = lv_pm_create_page(1);
  page2->onLoad = page_page2_onLoad;
  page2->unLoad = page_page2_unLoad;

  lv_pm_open_options_t options = {
    .animation = LV_PM_ANIMA_SLIDE
  };

  lv_pm_open_page(0, &options);
  lv_pm_open_page(1, &options);
  lv_pm_back();
}
