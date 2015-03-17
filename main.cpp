#include <iostream>
#include <vector>
#include "Board.h"
#include "Simulator.h"

int main()
{
    Board brd;
    std::cout << brd << std::endl;

    Simulator sim;
    sim.simulate(brd);



    return 0;
}
