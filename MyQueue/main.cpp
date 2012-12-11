#include "Queue.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Queue<int>* queue = new Queue<int>;
	queue->push(1);
	queue->push(2);
	queue->push(3);
	queue->push(4);
	queue->push(5);
	queue->push(6);
	queue->push(7);
	std::cout << "stack count: " << queue->count() << std::endl;
	
	Queue<int>::Node* pNode = NULL;
	while (queue->isEmpty() != true)
	{
		pNode = queue->pop();
		std::cout << pNode->data << std::endl;
		delete pNode;
	}
	std::cout << "stack is empty? " << std::boolalpha << queue->isEmpty() << std::endl << std::endl;

	return 0;
}