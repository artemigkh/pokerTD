cmake_minimum_required(VERSION 3.6)
project(pokerTD)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/SFML-2.4.2/cmake/Modules)
set(SFML_ROOT ${PROJECT_SOURCE_DIR}/SFML-2.4.2/)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)
add_executable(pokerTD ${SOURCE_FILES} src/main.cpp)
target_link_libraries(pokerTD ${SFML_LIBRARIES})
