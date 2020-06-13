#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
	Queue<string> queue(10);
	queue.enqueue("peter");
	queue.enqueue("paul");
	queue.enqueue("mary");
	cout<<queue.dequeue()<<endl;
	cout<<queue.getFront()<<endl;
}
