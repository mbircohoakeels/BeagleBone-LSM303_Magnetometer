cmake_minimum_required(VERSION 3.5)
project(LSM303_Magnetometer)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_SYSROOT /Volumes/xtools/arm-none-linux-gnueabi/arm-none-linux-gnueabi/sysroot/)

set(CMAKE_CXX_COMPILER /Volumes/xtools/arm-none-linux-gnueabi/bin/arm-none-linux-gnueabi-g++)

set(SOURCE_FILES
        example.cpp
        Lib/LSM303/Magnetometer/LSM303Magnetometer.cpp
        Lib/LSM303/Magnetometer/LSM303Magnetometer.h
        Lib/LSM303/LSM303DLHC.cpp
        Lib/LSM303/LSM303DLHC.h
        Lib/I2C/I2CDevice.h
        Lib/I2C/I2CDevice.cpp
        Lib/Exceptions/ExceptionAid.h)
add_executable(LSM303_Magnetometer ${SOURCE_FILES})