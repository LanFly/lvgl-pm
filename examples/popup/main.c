#include "pm.h"

#include "page/page1/page1.h"
#include "page/popup/popup.h"

lv_pm_open_options_t options = {
  .animation = LV_PM_ANIMA_SLIDE
};

lv_pm_open_options_t popupOptions = {
  .animation = LV_PM_ANIMA_POPUP
};

bool open = false;
void timer_cb(lv_timer_t *timer)
{
  if (open) {
    lv_pm_back();
    open = false;
  } else {
    lv_pm_open_page(1, &popupOptions);
    open = true;
  }
}

void app_start()
{
  lv_pm_init();

  lv_pm_page_t *page1 = lv_pm_create_page(0);
  page1->onLoad = page_page1_onLoad;
  page1->unLoad = page_page1_unLoad;

  lv_pm_page_t *popup = lv_pm_create_page(1);
  popup->onLoad = page_popup_onLoad;
  popup->unLoad = page_popup_unLoad;

  lv_pm_open_page(0, &options);
  lv_timer_create(timer_cb, 1000, NULL);
}
