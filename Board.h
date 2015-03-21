#pragma once
#include <vector>
#include <ostream>
#include <string>


class Board
{
    public:
        using BoardSize = std::vector<std::vector<std::string>>::size_type;

        friend std::ostream &operator<<(std::ostream &, const Board &);
    public:
        Board();
        BoardSize size();
        std::string& rowCol(BoardSize r, BoardSize c);
        const  std::string& col(BoardSize c) const;

    private:
        std::vector<std::vector<std::string>> board;
        BoardSize N;
};
