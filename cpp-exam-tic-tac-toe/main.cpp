#include <iostream>
#include "enums.h"
#include "Game.h"
#include "enums.h"

int main(int argc, char const *argv[])
{
    Game game(4, 4);

    game.play(Game::CellDto(0, 0));
    game.play(Game::CellDto(1, 0));
    game.play(Game::CellDto(0, 1));
    game.play(Game::CellDto(1, 1));
    game.play(Game::CellDto(0, 2));
    game.play(Game::CellDto(1, 2));
    game.play(Game::CellDto(0, 3));

    std::cout << game << std::endl;

    if (game.get_state() == GameStateEnum::X_WON) {
        std::cout << "X won!" << std::endl;
    }

    if (game.get_state() == GameStateEnum::O_WON) {
        std::cout << "O won!" << std::endl;
    }

    return 0;
}
