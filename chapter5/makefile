hash: hash.out
	
hash.out: hash.o
	g++ hash.o -o hash.out

hash.o: hash.cpp chainhashing.h linearhash.h
	g++ -c hash.cpp
