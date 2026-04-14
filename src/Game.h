#pragma once

#include "Board.h"

class Game
{
public:
    enum class Player { X, O };
    enum class Result { InProgress, XWins, OWins, Draw };

    Game();

    void reset();

    Player currentPlayer() const;
    Result result() const;
    const Board& board() const;

    // Returns true if the move was applied
    bool makeMove(int row, int col);

private:
    Board  m_board{};
    Player m_currentPlayer{Player::X};
    Result m_result{Result::InProgress};

    static Board::Cell playerToCell(Player p);
    void updateResult();
    void switchPlayer();
};
