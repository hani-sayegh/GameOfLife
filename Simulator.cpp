#include "Simulator.h"
#include "Board.h"

Simulator::Simulator()
{

}

void Simulator::simulate(Board& brd)
{
    // A live cell with fewer than 2 live neighbors dies.

    for (Board::BoardSize i = 0; i < brd.getSize(); ++i)
    {
    }
}
