cmake_minimum_required(VERSION 3.6)
project(pokerTD)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/SFML-2.4.2/cmake/Modules)
set(SFML_ROOT ${PROJECT_SOURCE_DIR}/SFML-2.4.2/)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/StateManager/GameStateInterface.cpp src/include/GameStateInterface.h src/StateManager/GameEngine.cpp src/include/GameEngine.h src/PlayState/Controller/PlayState.cpp src/include/PlayState.h src/include/GameConstants.h src/PlayState/Model/PlayStateModel.cpp src/include/PlayStateModel.h src/PlayState/Draw/PlayStateDrawObject.cpp src/include/PlayStateDrawObject.h src/PlayState/Model/Terrain.cpp src/include/Terrain.h src/PlayState/TerrainTypes.h lib/tinyxml2.cpp lib/tinyxml2.h src/PlayState/Model/Wave.cpp src/include/Wave.h src/PlayState/Model/WaveUnits.cpp src/include/WaveUnits.h src/PlayState/Draw/SpriteDrawObject.cpp src/include/SpriteDrawObject.h src/PlayState/Draw/GraphicsConstants.h src/PlayState/Model/Unit.cpp src/include/Unit.h src/PlayState/Draw/TowerMenuDrawer.cpp src/include/TowerMenuDrawer.h src/PlayState/Model/Tower.cpp src/include/Tower.h src/include/HandsEnum.h src/PlayState/Model/ActiveTower.cpp src/include/ActiveTower.h src/Poker/Cards/Deck.cpp src/include/Deck.h src/Poker/Cards/Card.cpp src/include/Card.h src/Poker/Cards/PokerHand.cpp src/include/PokerHand.h src/Poker/Cards/SuitsEnum.h src/Poker/Cards/CardValuesEnum.h src/Poker/pokerFunctions.h src/Poker/pokerFunctions.cpp src/PlayState/Draw/ActiveTowerDrawer.cpp src/include/ActiveTowerDrawer.h)
add_executable(pokerTD ${SOURCE_FILES} src/main.cpp)
target_link_libraries(pokerTD ${SFML_LIBRARIES})
