linkedlist: linkedlist.out
	
linkedlist.out: linkedlist.o
	g++ linkedlist.o -o linkedlist.out

linkedlist.o: linkedlist.cpp linkedlistNode.h linkedlistItr.h linkedlistList.h 
	g++ -c linkedlist.cpp



polynomial: linkedlist2.out
	
linkedlist2.out: linkedlist.o polynomial.o
	g++ linkedlist.o -o polynomial.out

linkedlist.o: linkedlist.cpp linkedlistNode.h linkedlistItr.h linkedlistList.h polynomial.h
	g++ -c linkedlist.cpp



polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp
	
stack: stack.out
	
stack.out: stack.o
	g++ stack.o -o stack.out

stack.o: stack.cpp stack.h
	g++ -c stack.cpp
	
queue: queue.out
	
queue.out: queue.o
	g++ queue.o -o queue.out

queue.o: queue.cpp queue.h
	g++ -c queue.cpp
	

