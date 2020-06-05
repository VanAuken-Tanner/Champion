add_library(primary game.cpp character.cpp player.cpp enemy.cpp enemyGenerator.cpp battleManager.cpp graphicsManager.cpp dice.cpp)

add_executable(game main.cpp)

target_link_libraries(game primary ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})