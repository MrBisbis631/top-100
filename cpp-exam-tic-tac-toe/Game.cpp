#include <iostream>
#include <vector>
#include "Game.h"
#include "enums.h"
#include "game-exceptions.cpp"

Game::Game(int board_dimensions, int sequence_size_to_win)
    : board(board_dimensions, std::vector<CellEnum>(board_dimensions, CellEnum::EMPTY)),
      player_turn(GameStateEnum::X_TURN),
      sequence_size_to_win(sequence_size_to_win)
{
    if (board_dimensions < sequence_size_to_win)
    {
        throw IllegalBoardConfigurationException();
    }

    if (board_dimensions < 1)
    {
        throw IllegalBoardConfigurationException();
    }
}

GameStateEnum Game::get_state() const
{
    return player_turn;
}

void Game::play(CellDto cell)
{
    if (cell.row < 0 || cell.row >= board.size() || cell.col < 0 || cell.col >= board.size())
    {
        throw IllegalMoveException();
    }

    if (board[cell.row][cell.col] != CellEnum::EMPTY)
    {
        throw IllegalMoveException();
    }

    board[cell.row][cell.col] = (player_turn == GameStateEnum::X_TURN) ? CellEnum::X : CellEnum::O;

    if (check_win(cell.row, cell.col))
    {
        player_turn = (player_turn == GameStateEnum::X_TURN) ? GameStateEnum::X_WON : GameStateEnum::O_WON;
    }
    else
    {
        player_turn = (player_turn == GameStateEnum::X_TURN) ? GameStateEnum::O_TURN : GameStateEnum::X_TURN;
    }
}

std::ostream &operator<<(std::ostream &os, const Game &game)
{
    for (const auto &row : game.board)
    {
        for (const auto &cell : row)
        {
            switch (cell)
            {
            case CellEnum::X:
                os << 'X';
                break;
            case CellEnum::O:
                os << 'O';
                break;
            default:
                os << '.';
                break;
            }
            os << ' ';
        }
        os << '\n';
    }
    return os;
}

bool Game::check_win(int row, int col) const
{
    CellEnum current_player = board[row][col];

    // Check horizontal
    int count = 1;
    for (int c = col - 1; c >= 0 && board[row][c] == current_player; --c)
    {
        count++;
    }
    for (int c = col + 1; c < board.size() && board[row][c] == current_player; ++c)
    {
        count++;
    }
    if (count >= sequence_size_to_win)
    {
        return true;
    }

    // Check vertical
    count = 1;
    for (int r = row - 1; r >= 0 && board[r][col] == current_player; --r)
    {
        count++;
    }
    for (int r = row + 1; r < board.size() && board[r][col] == current_player; ++r)
    {
        count++;
    }
    if (count >= sequence_size_to_win)
    {
        return true;
    }

    // Check diagonal (top-left to bottom-right)
    count = 1;
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0 && board[r][c] == current_player; --r, --c)
    {
        count++;
    }
    for (int r = row + 1, c = col + 1; r < board.size() && c < board.size() && board[r][c] == current_player; ++r, ++c)
    {
        count++;
    }
    if (count >= sequence_size_to_win)
    {
        return true;
    }

    // Check diagonal (top-right to bottom-left)
    count = 1;
    for (int r = row - 1, c = col + 1; r >= 0 && c < board.size() && board[r][c] == current_player; --r, ++c)
    {
        count++;
    }
    for (int r = row + 1, c = col - 1; r < board.size() && c >= 0 && board[r][c] == current_player; ++r, --c)
    {
        count++;
    }
    if (count >= sequence_size_to_win)
    {
        return true;
    }

    return false;
}