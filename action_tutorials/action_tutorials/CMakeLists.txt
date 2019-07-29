cmake_minimum_required(VERSION 2.8.3)
project(action_tutorials)

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

add_definitions(-std=c++11)
set(CMAKE_BUILD_TYPE Release)

#############
# LIBRARIES #
#############
cs_add_library(${PROJECT_NAME}
  src/fibonacci_server.cpp
)
target_link_libraries(${PROJECT_NAME})

############
# BINARIES #
############
cs_add_executable(fibonacci_server_node src/fibonacci_server_node.cpp)
target_link_libraries(fibonacci_server_node  ${PROJECT_NAME})

##########
# EXPORT #
##########
cs_install()
cs_export()