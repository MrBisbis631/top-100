#pragma once

#include "enums.h"
#include <vector>
#include <iostream>

class Game
{
    friend std::ostream &operator<<(std::ostream &os, const Game &game);

private:
    std::vector<std::vector<CellEnum>> board;
    int sequence_size_to_win;
    GameStateEnum player_turn;

    bool check_win(int row, int col) const;

public:
    struct CellDto
    {
        int row;
        int col;
    };

    Game(int board_dimensions, int sequence_size_to_win);
    ~Game() = default;

    GameStateEnum get_state() const;
    void play(CellDto cell);
};
