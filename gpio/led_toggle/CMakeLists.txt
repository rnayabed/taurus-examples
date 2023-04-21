cmake_minimum_required(VERSION 3.16)

set(VERSION 1.0)

find_package(taurus 1.0 REQUIRED)

project(led_toggle 
    VERSION ${VERSION}
    LANGUAGES C
    DESCRIPTION "LED Toggle")

add_executable(led_toggle
    led_toggle.c
)


target_link_libraries(led_toggle 
PRIVATE taurus::taurus)
