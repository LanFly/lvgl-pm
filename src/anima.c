#include "anima.h"
#include "pm.h"

#include "lvgl.h"
#include <stdlib.h>

lv_anim_t appear_anima;
lv_anim_t disAppear_anima;

typedef struct _lv_pm_anima_data {
  lv_pm_page_t *pm_page;
  lv_pm_anima_complete_cb cb;
} lv_pm_anima_data;

static void translateX_anima_cb(void *var, int32_t v)
{
  lv_obj_set_x(var, v);
}

static void anima_ready_cb(lv_anim_t *anim)
{
  lv_pm_anima_data *cb_data = (lv_pm_anima_data *)anim->user_data;
  cb_data->cb(cb_data->pm_page);
}

static void _pm_slide_appear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb)
{
  lv_coord_t width = lv_disp_get_hor_res(NULL);
  lv_pm_anima_data *cb_data = (lv_pm_anima_data *)malloc(sizeof(lv_pm_anima_data));
  if (cb_data == NULL) {
    cb(pm_page);
    return;
  }

  cb_data->pm_page = pm_page;
  cb_data->cb = cb;

  lv_anim_init(&appear_anima);
  lv_anim_set_user_data(&appear_anima, (void *)cb_data);
  lv_anim_set_var(&appear_anima, pm_page->page);
  lv_anim_set_values(&appear_anima, width, 0);
  lv_anim_set_time(&appear_anima, 500);
  lv_anim_set_repeat_count(&appear_anima, 1);
  lv_anim_set_exec_cb(&appear_anima, translateX_anima_cb);
  lv_anim_set_ready_cb(&appear_anima, anima_ready_cb);
  lv_anim_set_path_cb(&appear_anima, lv_anim_path_ease_out);
  lv_anim_start(&appear_anima);
}

static void _pm_slide_disAppear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb)
{
  lv_coord_t width = lv_disp_get_hor_res(NULL);
  lv_pm_anima_data *cb_data = (lv_pm_anima_data *)malloc(sizeof(lv_pm_anima_data));
  if (cb_data == NULL) {
    cb(pm_page);
    return;
  }

  cb_data->pm_page = pm_page;
  cb_data->cb = cb;

  lv_anim_init(&disAppear_anima);
  lv_anim_set_user_data(&disAppear_anima, (void *)cb_data);
  lv_anim_set_var(&disAppear_anima, pm_page->page);
  lv_anim_set_values(&disAppear_anima, 0, -width);
  lv_anim_set_time(&disAppear_anima, 500);
  lv_anim_set_repeat_count(&disAppear_anima, 1);
  lv_anim_set_exec_cb(&disAppear_anima, translateX_anima_cb);
  lv_anim_set_ready_cb(&disAppear_anima, anima_ready_cb);
  lv_anim_set_path_cb(&disAppear_anima, lv_anim_path_ease_out);
  lv_anim_start(&disAppear_anima);
}

void _pm_anima_appear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb)
{
  if (behavior == NULL || behavior->animation == LV_PM_ANIMA_NONE) {
    cb(pm_page);
    return;
  }

  switch (behavior->animation)
  {
  case LV_PM_ANIMA_SLIDE:
    _pm_slide_appear(pm_page, behavior, cb);
    break;
  default:
    cb(pm_page);
    break;
  }
}

void _pm_anima_disAppear(lv_pm_page_t *pm_page, lv_pm_open_options_t *behavior, lv_pm_anima_complete_cb cb)
{
  if (behavior == NULL || behavior->animation == LV_PM_ANIMA_NONE) {
    cb(pm_page);
    return;
  }

  switch (behavior->animation)
  {
  case LV_PM_ANIMA_SLIDE:
    _pm_slide_disAppear(pm_page, behavior, cb);
    break;
  default:
    cb(pm_page);
    break;
  }
}