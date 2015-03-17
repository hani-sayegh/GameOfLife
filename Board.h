#pragma once
#include <vector>
#include <ostream>

class Board
{
    using BoardSize = std::vector<std::vector<std::string>>::size_type;

    friend std::ostream &operator<<(std::ostream &, const Board &);
    public:
    Board();

    private:
    std::vector<std::vector<std::string>> board;
    BoardSize N = board.size();
};
