set(demo helloworld)
set(lvgl_sim_x ../lvgl-simulator-x)

cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME lvgl-pm-demo)

project(${PROJECT_NAME})

file(GLOB_RECURSE lvgl_SRCS ${demo}/*.c)
aux_source_directory(../src pm_SRCS)

include_directories(${lvgl_sim_x})
include_directories(../src)

add_executable(${PROJECT_NAME} ${lvgl_SRCS} ${pm_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${demo})

add_subdirectory(${lvgl_sim_x} lvgl-sim-x)

target_link_libraries(${PROJECT_NAME} lvgl-sim)
