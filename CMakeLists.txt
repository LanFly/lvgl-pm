cmake_minimum_required(VERSION 3.5)

if(NOT ESP_PLATFORM)
  project(pm)
endif()

file(GLOB_RECURSE SOURCES src/*.c)

if(ESP_PLATFORM)
  idf_component_register(SRCS ${SOURCES}
                         INCLUDE_DIRS src
                         REQUIRES lvgl)
else()
  include_directories(src)

  add_library(pm STATIC ${SOURCES})
endif()
