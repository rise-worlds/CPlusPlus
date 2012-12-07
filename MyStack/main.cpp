#include <iostream>
#include "Stack.h"

int main(int argc, char *argv[], char *envp[])
{
	Stack<int>* stack = new Stack<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	std::cout << "stack count: " << stack->count() << std::endl;
	Stack<int>::Node* pNode = NULL;
	while (stack->top() != NULL)
	{
		pNode = stack->pop();
		std::cout << pNode->data << std::endl;
		delete pNode;
	}
	std::cout << "stack count: " << stack->count() << std::endl;
	system("pause");
	return 0;
}