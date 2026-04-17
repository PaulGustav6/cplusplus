#pragma once

#include "Board.h"

// Game nimmt den Spielablauf auf, damit main.cpp nicht zum Mischmasch aus allem wird.
// Für ein 3x3-Spiel reicht diese eine Trennung komplett aus.
class Game
{
public:
    enum class Player { X, O };
    enum class Result { InProgress, XWins, OWins, Draw };

    Game() = default;

    void reset();

    Player currentPlayer() const;
    Result result() const;
    const Board& board() const;

    bool makeMove(int row, int col);

private:
    Board  m_board{};
    Player m_currentPlayer{Player::X};
    Result m_result{Result::InProgress};

    static Board::Cell playerToCell(Player p);
    void updateResult();
    void switchPlayer();
};
