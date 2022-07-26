# LVGL-PM

![version v0.1.1](https://img.shields.io/badge/version-v0.1.1-brightgreen)
![license MIT](https://img.shields.io/badge/license-MIT-green)

**[English Document](./README-en.md)**

一个为 LVGL 精心定制的 APP 页面管理器，简单易用，功能强大，支持多种酷炫动画

## 特性

简单、易用、强大

- 支持页面全生命周期管理，参考手机 APP 生命周期
- 支持多种酷炫动画，内置集成
- 多个页面代码隔离，单文件开发体验

## 使用示例

```c
#include "pm.h"

void main()
{
  lv_pm_init();

  lv_pm_page_t *home = lv_pm_create_page(0);
  page->onLoad = page_home_onLoad; // 需要你实现的页面函数
  page->unLoad = page_home_unLoad; // 需要你实现的页面函数

  lv_pm_open_page(0, NULL);
}
```

## 编写页面

```c
// home.c

#include "home.h"

void page_home_onLoad(lv_obj_t *page)
{
  // 所有对象都挂载在 page 下面，页面管理器会自动帮你管理内存
  lv_obj_t *label = lv_label_create(page);
  lv_label_set_text(label, "hello home page");
}

void page_home_unLoad(lv_obj_t *page)
{
  // onLoad 和 unLoad 必须实现，所有挂载在 page 下的对象都会自动释放
  // 你只需要释放自己申请的内存
}
```

## API

### uint8_t lv_pm_init()
--------------------------

这个函数必须在使用任何页面管理器 API 之前调用

返回 0 表示 OK，其它值表示错误，你需要自己处理错误

### lv_pm_page_t \*lv_pm_create_page(uint8_t id)
--------------------------

创建一个路由并且指定路由标识 ID，这个 ID 在打开页面时会用到，必须唯一。

一般 ID 从下标 0 开始，你可以按照页面的顺序来分配 ID

> 注意：默认路由表长度是 10，所以你不能使用超过长度的 ID 值，如果大于 10，你可以使用 `#define LV_PM_PAGE_NUM 20` 指定长度

创建好路由后，你可以注册页面的生命周期函数了，此时并不会真正的创建页面

下面 2 个生命周期是必须实现的:
 
 1. onLoad
 2. unLoad

### uint8_t lv_pm_open_page(uint8_t id, lv_pm_open_options_t \*behavior)
--------------------------

根据指定的路由 ID 打开页面，此时会调用 onLoad 真正创建页面

参数 `behavior`：指定打开页面的行为，过渡动画，打开方式，动画方向。默认为 `NULL`

> 注意：为了页面代码简单，我们并没有实现多实例。所以一个路由 ID 同时只能被打开一次，打开 2 次以上的行为是未定义的，会产生不可预期的错误
> 在未来的版本中，我们会支持页面多实例

示例：
```c
#include "pm.h"

lv_pm_open_options_t options = {
  .animation = LV_PM_ANIMA_SLIDE // 使用滑动动画打开页面
};

lv_pm_open_page(0, &options);
// 或者使用默认行为 lv_pm_open_page(0, NULL);
```

### uint8_t lv_pm_back()
--------------------------

关闭当前页面并且显示上一个页面。如果当前只有一个页面或者没有打开页面，则此函数什么也不做

## 完整的生命周期

1. onLoad          : 页面创建，你可以在这里执行初始化
2. willAppear      : 页面即将被展示
3. didAppear       : 页面已经被完整展示
4. willDisappear   : 页面即将被隐藏
5. didDisappear    : 页面已经被隐藏不可见
6. unLoad          : 页面被关闭，你需要在这里释放所有临时内存，否则可能存在泄漏

## 内置过渡动画

- [x] LV_PM_ANIMA_NONE: 不使用过渡动画
- [x] LV_PM_ANIMA_SLIDE: 滑动动画，页面从右往左出现，从左往右消失
- [ ] LV_PM_ANIMA_SLIDE_SCALE: 滑动并缩放页面，页面从右往左先出现，再放大全屏
- [ ] 更多动画开发中，欢迎贡献代码，开发过渡动画非常简单