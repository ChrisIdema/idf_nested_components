cmake_minimum_required(VERSION 3.5)
set(SUPPORTED_TARGETS esp32)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
#set(EXTRA_COMPONENT_DIRS components/component1/components)
project(nested_components)

