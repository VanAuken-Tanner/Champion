add_library(character character.cpp player.cpp enemy.cpp enemyGenerator.cpp)
add_library(engine battleManager.cpp graphicsManager.cpp)

add_executable(game main.cpp)

target_link_libraries(game character engine)