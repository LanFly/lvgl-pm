# LVGL-PM

**【中文文档】马上来**

A simple page manager for LVGL.

## Features

simple and easy to use.

- Page lifecycle management
- Support transition animation

## Example

```c
#include "pm.h"

void main()
{
  lv_pm_init();

  lv_pm_page_t *home = lv_pm_create_page(0);
  page->onLoad = page_home_onLoad; // you should implement this function
  page->unLoad = page_home_unLoad; // you should implement this function

  lv_pm_open_page(0, NULL);
}
```

## Write a page

```c
// home.c

#include "home.h"

void page_home_onLoad(lv_obj_t *page)
{
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello home page");
}

void page_home_unLoad(lv_obj_t *page)
{
  // all children of page will be deleted automatically.
}
```

## API

**uint8_t lv_pm_init()**

This function muse be called before using LVGL-PM.

return 0 is OK.

**lv_pm_page_t \*lv_pm_create_page(uint8_t id)**

Create a page and specify an ID. The ID is used for lv_pm_open_page API.

There are 2 lifecycle that must be registered:
 
 1. onLoad
 2. unLoad

**uint8_t lv_pm_open_page(uint8_t id, lv_pm_open_options_t \*behavior)**

Open the page according to the specified ID.

> Warning: A specified page ID can only be opened once at time. In the future version, we will support multi page instances.

**uint8_t lv_pm_back()**

Close the current page and display the previous page. Do nothing if there is only one page or nothing.

## Lifecycle

1. onLoad
2. willAppear
3. didAppear
4. willDisappear
5. didDisappear
6. unLoad

## buildin animation

- LV_PM_ANIMA_NONE (support)
- LV_PM_ANIMA_SLIDE (support)
- LV_PM_ANIMA_SLIDE_SCALE (not yet)