#include "Simulator.h"
#include "Board.h"
#include <iostream>

Simulator::Simulator()
{

}



void Simulator::simulate(Board& brd)
{
    // A live cell with fewer than 2 live neighbors dies.

    for (Board::BoardSize i = 0; i < brd.getRow(); ++i)
    {
        for (Board::BoardSize j = 0; j < brd.getCol(); ++j)
        {
            if(brd.rowCol(i,j) == "*")
            {
                std::cout << "Yeeee" << std::endl;
            }
        }
    }
}
