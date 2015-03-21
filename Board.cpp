#include "Board.h"
#include <ostream>
#include <string>

Board::Board() // Default board is 10 x 10
{
    std::vector<std::string> v;
    for (unsigned i = 0; i < 10; ++i)
    {
        v.push_back("# ");
    }
    for (unsigned i = 0; i < 10; ++i)
    {
        if(i == 4)
        {
            v.at(i) = "* ";
            board.push_back(v);
            v.at(i) = "# ";
        }
        else
        {
            board.push_back(v);
        }
    }
    N = board.size();
}

std::ostream& operator<<(std::ostream &os, const Board &brd)
{
    for(auto & b : brd.board)
    {
        for(auto &v: b)
        {
            os << v ;
        }
        os << std::endl;
    }
    return os ;
}

Board::BoardSize Board::size()
{
    return N;
}


std::string & Board::rowCol(BoardSize r, BoardSize c)
{
    return board.at(r).at(c);
}

