cmake_minimum_required(VERSION 3.10.0)
project(eventLogger VERSION 0.1.0 LANGUAGES C)

add_executable(eventLogger src/main.c)

target_include_directories(eventLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(eventLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/staticEventBuffer)
target_include_directories(eventLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/dynamicEventBuffer)

