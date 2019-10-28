MinMaxHeap: main.o Executive.o MinMaxHeap.o
	g++ -g -std=c++11 main.o Executive.o MinMaxHeap.o -o MinMaxHeap

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp MinMaxHeap.h
	g++ -std=c++11 -g -c Executive.cpp

MinMaxHeap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -std=c++11 -g -c MinMaxHeap.cpp

clean:
	rm *.o MinMaxHeap
