#ifndef PM_H
#define PM_H

#include "lvgl.h"
#include <stdint.h>

#define LV_PM_MAJOR 0
#define LV_PM_MINOR 1
#define LV_PM_PATCH 1

typedef void (*lv_pm_lifecycle)(lv_obj_t *page);

enum LV_PM_PAGE_ANIMA {
  LV_PM_ANIMA_NONE = 0,
  LV_PM_ANIMA_SLIDE = 1,
  LV_PM_ANIMA_SLIDE_SCALE = 2,
  LV_PM_ANIMA_POPUP = 3
};

enum LV_PM_ANIMA_DIR {
  LV_PM_ANIMA_TOP = 0,
  LV_PM_ANIMA_RIGHT = 1,
  LV_PM_ANIMA_BOTTOM = 2,
  LV_PM_ANIMA_LEFT = 3
};

enum LV_PM_OPEN_TARGET {
  // open in new page
  LV_PM_TARGET_NEW = 0,
  // replace current page
  LV_PM_TARGET_SELF = 1,
  // close all page and open in new page
  LV_PM_TARGET_RESET = 2
};

typedef struct _lv_pm_open_options_t
{
  enum LV_PM_PAGE_ANIMA animation;
  enum LV_PM_OPEN_TARGET target;
  enum LV_PM_ANIMA_DIR direction;
} lv_pm_open_options_t;

typedef struct _lv_pm_page_t
{
  lv_obj_t *page;
  lv_pm_lifecycle onLoad;
  lv_pm_lifecycle willAppear;
  lv_pm_lifecycle didAppear;
  lv_pm_lifecycle willDisappear;
  lv_pm_lifecycle didDisappear;
  lv_pm_lifecycle unLoad;
  lv_pm_open_options_t _options;
  bool _back;
} lv_pm_page_t;


uint8_t lv_pm_history_len;

#ifndef LV_PM_PAGE_NUM
#define LV_PM_PAGE_NUM 10
#endif

lv_pm_page_t *lv_pm_router[LV_PM_PAGE_NUM];
uint8_t lv_pm_history[LV_PM_PAGE_NUM];

uint8_t lv_pm_init();

lv_pm_page_t *lv_pm_create_page(uint8_t id);

uint8_t lv_pm_open_page(uint8_t id, lv_pm_open_options_t *behavior);

uint8_t lv_pm_back();

#endif