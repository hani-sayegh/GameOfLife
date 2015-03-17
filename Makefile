GameOfLife.out: main.o Board.o Simulator.o
	g++ -std=c++11 main.o Board.o Simulator.o -o GameOfLife.out

main.o : main.cpp Board.h
	g++ -std=c++11 -Wall -c main.cpp

Board.o : Board.cpp Board.h
	g++ -std=c++11 -Wall -c Board.cpp

Simulator.o : Simulator.cpp Simulator.h Board.h
	g++ -std=c++11 -Wall -c Simulator.cpp

clean:
	rm *.o GameOfLife.out
