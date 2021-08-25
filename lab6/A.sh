g++ -c memory.cpp
g++ -c FIFO.cpp
g++ -c LRU.cpp
g++ -c OPR.cpp
g++ memory.o FIFO.o LRU.o OPR.o -o memory
rm *.o