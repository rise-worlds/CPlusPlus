#include <iostream>
using namespace std;
#include "Stack.h"

int main(int argc, char *argv[], char *envp[])
{
	Stack<int>* stack = new Stack<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	return 0;
}