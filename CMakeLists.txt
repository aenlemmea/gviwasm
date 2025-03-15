cmake_minimum_required(VERSION 3.28)
project(gviwasm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "CPP STANDARD: 20")
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND SRC src/main.cpp)

add_executable(gviwasm ${SRC})
target_include_directories(gviwasm PUBLIC ${CMAKE_SOURCE_DIR}/include)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

# add_definitions(-DBOOST_ALL_NO_LIB)
# add_definitions(-DBOOST_ALL_DYN_LINK)
# find_package(Boost COMPONENTS system unit_test_framework)

add_executable(test_gvi ${CMAKE_SOURCE_DIR}/tests/test_node.cc)
target_include_directories(test_gvi PUBLIC ${CMAKE_SOURCE_DIR}/include)
find_package(Boost 1.70 COMPONENTS program_options REQUIRED)
target_include_directories(test_gvi PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(test_gvi ${Boost_LIBRARIES} )
