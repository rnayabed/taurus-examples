cmake_minimum_required(VERSION 3.16)

find_package(taurus 1.0 REQUIRED)

project(4x3_keypad_demo
    LANGUAGES C)

add_executable(${PROJECT_NAME}
    4x3_keypad_demo.c)

target_link_libraries(${PROJECT_NAME}
    PRIVATE taurus::taurus)

configure_taurus_uploader(
    START_AFTER_UPLOAD
    TARGET_PATH /dev/ttyUSB0)

