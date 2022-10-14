cmake_minimum_required (VERSION 3.10)
project (Adafruit_ADS1X15_Pi)

include_directories(${CMAKE_SOURCE_DIR})
add_library(ADS1X15 STATIC Adafruit_ADS1X15.cpp)
target_link_libraries(ADS1X15 i2c) 

add_subdirectory (examples)

