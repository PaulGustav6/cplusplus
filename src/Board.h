#pragma once

#include <array>
#include <optional>

class Board
{
public:
    enum class Cell { Empty, X, O };

    static constexpr int Size = 3;

    Board();

    void reset();
    bool isFull() const;
    Cell get(int row, int col) const;
    bool trySet(int row, int col, Cell value);

    // Returns X or O if a winner exists, nullopt otherwise
    std::optional<Cell> winner() const;

private:
    std::array<Cell, Size * Size> m_cells{};

    static int index(int row, int col);
};
