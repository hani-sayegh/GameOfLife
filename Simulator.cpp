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
            std::string alive = "* ";
            std::string & cell = brd.rowCol(i , j);
            if(cell == alive )
            {
                std::string topLeft = brd.rowCol(i - 1, j - 1);
                std::string topMid = brd.rowCol(i - 1, j - 1);
                std::string topRight = brd.rowCol(i - 1, j - 1);
                std::string bottomLeft = brd.rowCol(i - 1, j - 1);
                std::string bottomMid = brd.rowCol(i - 1, j - 1);
                std::string bottomRight = brd.rowCol(i - 1, j - 1);
                std::string sideLeft = brd.rowCol(i - 1, j - 1);
                std::string sideRight = brd.rowCol(i - 1, j - 1);

                unsigned neighbors = 0;
                if (topLeft == alive)
                {
                    ++neighbors;
                }
                if (topMid == alive)
                {
                    ++neighbors;
                }
                if (topRight == alive)
                {
                    ++neighbors;
                }
                if (bottomLeft == alive)
                {
                    ++neighbors;
                }
                if (bottomMid == alive)
                {
                    ++neighbors;
                }
                if (bottomRight == alive)
                {
                    ++neighbors;
                }
                if (sideLeft == alive)
                {
                    ++neighbors;
                }
                if (sideRight == alive)
                {
                    ++neighbors;
                }
                if(neighbors < 2)
                {
                    cell = "# ";
                }

            }
        }
    }
    std::cout << brd << std::endl;
}
