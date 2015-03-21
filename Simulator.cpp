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
    while(std::chrono::system_clock::now() > curr + sec);
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


    auto curr = std::chrono::system_clock::now();
    std::chrono::seconds sec{2}; // A duration of 2 seconds.
    while(std::chrono::system_clock::now() < curr + sec)
    {
        for (Board::BoardSize i = 0; i < brd.getRow(); ++i)
        {
            for (Board::BoardSize j = 0; j < brd.getCol(); ++j)
            {
                std::string alive = "* ";
                std::string & cell = cpy.rowCol(i , j);
                /* if(brd.rowCol(i, j) == alive ) */
                /* { */

                std::string topLeft     = brd.rowCol(i - 1, j - 1);
                std::string topMid      = brd.rowCol(i - 1, j - 1);
                std::string topRight    = brd.rowCol(i - 1, j - 1);
                std::string bottomLeft  = brd.rowCol(i - 1, j - 1);
                std::string bottomMid   = brd.rowCol(i - 1, j - 1);
                std::string bottomRight = brd.rowCol(i - 1, j - 1);
                std::string sideLeft    = brd.rowCol(i - 1, j - 1);
                std::string sideRight   = brd.rowCol(i - 1, j - 1);

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
