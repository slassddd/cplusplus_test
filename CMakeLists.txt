cmake_minimum_required(VERSION 2.8)

project(myMain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -o0 -Wall")

include_directories(include)

add_executable(main_mutex_uniquelock main_mutex_uniquelock.cc)
target_link_libraries(main_mutex_uniquelock pthread)

add_executable(main_vector_list main_vector_list.cc)
# target_link_libraries(main_vector_list pthread)