#include <iostream>
#include <chrono>

#include "Simulator.h"

Simulator::Simulator()
{

}

void wait(int seconds)
{
    auto curr = std::chrono::system_clock::now();
    std::chrono::seconds sec{seconds}; // A duration of 2 seconds.
    while(std::chrono::system_clock::now() < curr + sec);
}


void Simulator::simulate(Board& brd)
{
    Board cpy = brd;

    // A location that has zero or one neighbors will be empty in the next generation. If
    // a cell was in that location, it dies of loneliness.
    // A live cell with fewer than 2 live neighbors dies.
    //
    // A location with two neighbors is stable—that is, if it contained a cell, it still
    //  contains a cell. If it was empty, it's still empty.
    //
    //A location with three neighbors will contain a cell in the next generation. If it
    // was unoccupied before, a new cell is born. If it currently contains a cell, the cell
    // remains. Good times.
    //
    //  A location with four or more neighbors will be empty in the next generation. If
    // there was a cell in that location, it dies of overcrowding.


    Board::BoardSize N = brd.size();
    auto curr = std::chrono::system_clock::now();
    std::chrono::seconds sec{2}; // A duration of 2 seconds.
    while(std::chrono::system_clock::now() < curr + sec)
    {
        for (Board::BoardSize i = 0; i < N; ++i)
        {
            for (Board::BoardSize j = 0; j < N; ++j)
            {
                std::string alive = "* ";
                std::string & cell = cpy.rowCol(i , j);
                /* if(brd.rowCol(i, j) == alive ) */
                /* { */

                bool firstRow = (i == 0);
                bool lastRow  = (i == N - 1);
                bool firstCol = (j == 0);
                bool lastCol  = (j == N - 1);

                unsigned neighbors = 0;

                if(!(firstRow || firstCol))
                {
                    std::string topLeft     = brd.rowCol(i - 1, j - 1);
                    if (topLeft == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!firstRow)
                {
                    std::string topMid      = brd.rowCol(i - 1, j);
                    if (topMid == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!(firstRow || lastCol))
                {
                    std::string topRight    = brd.rowCol(i - 1, j + 1);
                    if (topRight == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!(firstCol || lastRow))
                {
                    std::string bottomLeft  = brd.rowCol(i + 1, j - 1);
                    if (bottomLeft == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!(lastRow))
                {
                    std::string bottomMid   = brd.rowCol(i + 1, j);
                    if (bottomMid == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!(lastCol || lastRow))
                {
                    std::string bottomRight = brd.rowCol(i + 1, j + 1);
                    if(bottomRight == alive)
                    {
                        ++neighbors;
                    }
                }

                if(!(firstCol))
                {
                    std::string sideLeft    = brd.rowCol(i, j - 1);
                    if (sideLeft == alive)
                    {
                        ++neighbors;
                    }
                }
                if(!(lastCol))
                {
                    std::string sideRight   = brd.rowCol(i, j + 1);
                    if (sideRight == alive)
                    {
                        ++neighbors;
                    }
                }
                if(neighbors < 2)
                {
                    cell = "# ";
                }
                else if(neighbors == 3)
                {
                    cell = "* ";
                }
                else if (neighbors == 4)
                {
                    cell = "# ";
                }
                /* } */
            }
        }
    }
    std::cout << brd << std::endl;
}
