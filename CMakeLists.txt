#This is the a Lupus manager
cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0048 NEW)

project(lupus VERSION 0.0)

set(sources gamemaster.cpp main.cpp)
set(progname ${PROJECT_NAME})

add_definitions(-DMAJOR=${PROJECT_VERSION_MAJOR} -DMINOR=${PROJECT_VERSION_MINOR} -DAPPNAME="${progname}")

# Use c++11
add_definitions(-std=gnu++11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)
find_package(Qt5Widgets)

get_target_property(QtWidgets_location Qt5::Widgets LOCATION)
get_target_property(QtCore_location Qt5::Core LOCATION)

add_executable(${progname} ${sources})

#target_link_libraries(${progname} Qt5::Core Qt5::Sql Qt5::Widgets )
