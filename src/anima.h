#ifndef PM_ANIMA_H
#define PM_ANIMA_H

#include "pm.h"

typedef void (*lv_pm_anima_complete_cb)(lv_pm_page_t *pm_page, lv_pm_open_options_t options);

void _pm_anima_appear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb);

void _pm_anima_disAppear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb);

#endif
