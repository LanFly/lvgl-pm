cmake_minimum_required(VERSION 3.5)

project(pm)

include_directories(src)

aux_source_directory(src SRCS)

add_library(pm STATIC ${SRCS})
