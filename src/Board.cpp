#include "Board.h"

void Board::reset()
{
    m_cells.fill(Cell::Empty);
}

int Board::index(int row, int col)
{
    return row * Size + col;
}

Board::Cell Board::get(int row, int col) const
{
    return m_cells.at(index(row, col));
}

bool Board::trySet(int row, int col, Cell value)
{
    const int i = index(row, col);
    if (m_cells.at(i) != Cell::Empty)
        return false;
    m_cells.at(i) = value;
    return true;
}

bool Board::isFull() const
{
    for (const auto c : m_cells)
        if (c == Cell::Empty)
            return false;
    return true;
}

std::optional<Board::Cell> Board::winner() const
{
    for (int r = 0; r < Size; ++r)
    {
        const Cell a = get(r, 0), b = get(r, 1), c = get(r, 2);
        if (a != Cell::Empty && a == b && b == c)
            return a;
    }

    for (int c = 0; c < Size; ++c)
    {
        const Cell a = get(0, c), b = get(1, c), c2 = get(2, c);
        if (a != Cell::Empty && a == b && b == c2)
            return a;
    }

    {
        const Cell a = get(0, 0), b = get(1, 1), c = get(2, 2);
        if (a != Cell::Empty && a == b && b == c)
            return a;
    }

    {
        const Cell a = get(0, 2), b = get(1, 1), c = get(2, 0);
        if (a != Cell::Empty && a == b && b == c)
            return a;
    }

    return std::nullopt;
}
