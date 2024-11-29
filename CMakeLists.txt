cmake_minimum_required(VERSION 3.8)
project(deskPet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_SOURCE
main.cpp
mainWindow.cpp
mainWindow.h
mainWindow.ui


   "videoByFrame.cpp" "videoByFrame.h" "res.h")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(deskPet ${PROJECT_SOURCE})#定义可执行文件名为deskPet

find_package(Qt6 REQUIRED COMPONENTS Widgets) 
target_link_libraries(deskPet PRIVATE Qt6::Widgets)#为deskPet链接Qt库

find_package(Qt6 REQUIRED COMPONENTS Multimedia) 
target_link_libraries(deskPet PRIVATE Qt6::Multimedia)