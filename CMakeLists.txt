cmake_minimum_required(VERSION 3.6)
project(pokerTD)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/SFML-2.4.2/cmake/Modules)
set(SFML_ROOT ${PROJECT_SOURCE_DIR}/SFML-2.4.2/)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/StateManager/GameStateInterface.cpp src/include/GameStateInterface.h src/StateManager/GameEngine.cpp src/include/GameEngine.h src/PlayState/Controller/PlayState.cpp src/include/PlayState.h src/include/const.h src/PlayState/Model/PlayStateModel.cpp src/include/PlayStateModel.h src/PlayState/Draw/PlayStateDrawObject.cpp src/include/PlayStateDrawObject.h src/PlayState/Model/Terrain.cpp src/include/Terrain.h src/PlayState/TerrainTypes.h lib/tinyxml2.cpp lib/tinyxml2.h src/PlayState/Model/Wave.cpp src/include/Wave.h src/PlayState/Model/WaveUnits.cpp src/include/WaveUnits.h)
add_executable(pokerTD ${SOURCE_FILES} src/main.cpp)
target_link_libraries(pokerTD ${SFML_LIBRARIES})
