g++ -c bankers.cpp
g++ -c safe.cpp
g++ -c check.cpp
g++ bankers.o safe.o check.o -o banker
rm *.o