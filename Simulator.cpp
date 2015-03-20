#include "Simulator.h"
#include "Board.h"
#include <iostream>
#include <chrono>

Simulator::Simulator()
{

}



void Simulator::simulate(Board& brd)
{

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

    std::chrono::time_point<std::chrono::system_clock> go, curr;
    curr = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = curr - go;
    go = std::chrono::system_clock::now();
    std::cout << "Here I am: " << elapsed_seconds.count() << std::endl;
    std::chrono::seconds sec(2);
    std::cout << "Here I am: " << sec.count() << std::endl;
    while(elapsed_seconds.count() < sec.count() )
    {
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
                    else if(neighbors == 3)
                    {
                        cell = "* ";
                    }
                    else if (neighbors == 4)
                    {
                        cell = "# ";
                    }
                }
            }
        }
        curr = std::chrono::system_clock::now();
        elapsed_seconds = curr - go;
    }
    std::cout << brd << std::endl;
}
