#include "pm_utils.h"

void pm_reset_style(lv_obj_t *obj)
{
  lv_obj_set_style_border_width(obj, 0, LV_STATE_DEFAULT);
  lv_obj_set_style_radius(obj, 0, LV_STATE_DEFAULT);
  lv_obj_set_style_pad_all(obj, 0, LV_STATE_DEFAULT);
}