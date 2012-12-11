#include <iostream>
#include "Stack.h"
#include "fibonacci.h"
#include "postfix.h"

int main(int argc, char *argv[], char *envp[])
{
	//Stack<int>* stack = new Stack<int>();
	//stack->push(1);
	//stack->push(2);
	//stack->push(3);
	//stack->push(4);
	//stack->push(5);
	//std::cout << "stack count: " << stack->count() << std::endl;
	//Stack<int>::Node* pNode = NULL;
	//while (stack->top() != NULL)
	//{
	//	//std::cout << stack->pop() << std::endl;
	//	pNode = stack->pop();
	//	std::cout << pNode->data << std::endl;
	//	delete pNode;
	//}
	//std::cout << "stack is empty? " << std::boolalpha << stack->empty() << std::endl << std::endl;

	//std::cout << "Fibonacci 40" << std::endl;
	//for (int i = 0; i < 40; i++)
	//{
	//	std::cout << Fibonacci(i) << " ";
	//}
	//std::cout << std::endl;

	std::cout << "Infix To Postfix " << std::endl;
	//char pre[] ="22/(5*2+1)#";
	char exp[100];
	char post[100] ;
	std::cout << "Input infix expression (# end):";
	std::cin >> exp;

	int n = 0;			// postfix expression lenght
	postfix(exp, post, n);
	std::cout << "Postfix expression for:";
	for( int i = 0; i < n; i++)
	{
		std::cout << post[i] ;
	}

	std::cout << std::endl << "The postfix expression calculated the numerical results: ";
	std::cout << postfix_value(post) << std::endl;

	system("pause");
	return 0;
}