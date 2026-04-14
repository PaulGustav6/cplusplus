#include "Game.h"

Game::Game()
{
    reset();
}

void Game::reset()
{
    m_board.reset();
    m_currentPlayer = Player::X;
    m_result = Result::InProgress;
}

Game::Player Game::currentPlayer() const { return m_currentPlayer; }
Game::Result Game::result()        const { return m_result; }
const Board& Game::board()         const { return m_board; }

Board::Cell Game::playerToCell(Player p)
{
    return (p == Player::X) ? Board::Cell::X : Board::Cell::O;
}

bool Game::makeMove(int row, int col)
{
    if (m_result != Result::InProgress)
        return false;

    if (!m_board.trySet(row, col, playerToCell(m_currentPlayer)))
        return false;

    updateResult();

    if (m_result == Result::InProgress)
        switchPlayer();

    return true;
}

void Game::switchPlayer()
{
    m_currentPlayer = (m_currentPlayer == Player::X) ? Player::O : Player::X;
}

void Game::updateResult()
{
    if (const auto w = m_board.winner())
    {
        m_result = (*w == Board::Cell::X) ? Result::XWins : Result::OWins;
        return;
    }
    m_result = m_board.isFull() ? Result::Draw : Result::InProgress;
}
