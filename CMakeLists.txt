cmake_minimum_required(VERSION 3.25.1)
project(Task_33_2)

#set(Boost_INCLUDE_DIR "c:\\boost_1_81_0")
#set(Boost_LIBRARY_DIR "c:\\boost_1_81_0\\stage\\lib")
#find_package(Boost COMPONENTS REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#link_directories(${Boost_LIBRARY_DIR})
#add_library(${PROJECT_NAME})
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src)



