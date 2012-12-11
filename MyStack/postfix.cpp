// PrefixToPostfix.cpp

#include "Stack.h"
#include "postfix.h"

#include <iostream>
using namespace std;

bool isoperator(char op)
{
	switch(op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default : 
		return 0;
	}
}


int priority(char op)
{
	switch(op)
	{
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default :
		return -1;
	}
}

//	 把中缀表达式转换为后缀表达式，返回后缀表达式的长度（包括空格）
void postfix(char pre[] ,char post[],int &n)
{
	int i = 0 ,j=0;
	Stack<char> stack;

	stack.push('#');	// 首先把结束标志‘#’放入栈底

	while(pre[i]!='#')
	{
		if((pre[i]>='0' && pre[i] <='9')||pre[i] =='.') // 遇到数字和小数点直接写入后缀表达式
		{
			post[j++] = pre[i];
			n++;
		}
		else if (pre[i]=='(')	// 遇到“（”不用比较直接入栈
			stack.push(pre[i]);
		else if(pre[i] ==')')	// 遇到右括号将其对应左括号后的操作符（操作符栈中的）全部写入后缀表达式
		{
			while(stack.top()->data!='(')
			{
				post[j++] = stack.pop()->data;
				n++;
			}
			stack.pop(); // 将“（”出栈，后缀表达式中不含小括号
		}
		else if (isoperator(pre[i]))
		{
			post[j++] = ' '; // 用空格分开操作数(
			n++;
			while(priority(pre[i]) <= priority(stack.top()->data)) 
			{
				// 当前的操作符小于等于栈顶操作符的优先级时，将栈顶操作符写入到后缀表达式，重复此过程
				post[j++] = stack.pop()->data;
				n++;
			}

			stack.push(pre[i]);	// 当前操作符优先级大于栈顶操作符的优先级，将该操作符入栈
		}

		i++;
	}
	while(stack.top() != NULL) // 将所有的操作符加入后缀表达式
	{
		post[j++] = stack.pop()->data;
		n++;
	}
}

double read_number(char str[],int *i)
{
	double x=0.0;
	int k = 0;
	while(str[*i] >='0' && str[*i]<='9')  // 处理整数部分
	{
		x = x*10+(str[*i]-'0');
		(*i)++;
	}

	if(str[*i]=='.') // 处理小数部分
	{
		(*i)++;
		while(str[*i] >= '0'&&str[*i] <='9')
		{
			x = x * 10 + (str[*i]-'0');
			(*i)++;
			k++;
		}
	}
	while(k!=0)
	{
		x /= 10.0;
		k--;
	}

	return x;
}

double postfix_value(char post[])
{
	Stack<double> stack;	// 操作数栈

	int i=0 ;
	double x1,x2;

	while(post[i] !='#')
	{
		if(post[i] >='0' && post[i] <='9')
			stack.push(read_number(post,&i));
		else if(post[i] == ' ')
			i++;
		else if (post[i] =='+')
		{
			x2 = stack.pop()->data;
			x1 = stack.pop()->data;
			stack.push(x1+x2);
			i++;
		}
		else if (post[i] =='-')
		{
			x2 = stack.pop()->data;
			x1 = stack.pop()->data;
			stack.push(x1-x2);
			i++;
		}
		else if (post[i] =='*')
		{
			x2 = stack.pop()->data;
			x1 = stack.pop()->data;
			stack.push(x1*x2);
			i++;
		}
		else if (post[i] =='/')
		{
			x2 = stack.pop()->data;
			x1 = stack.pop()->data;
			stack.push(x1/x2);
			i++;
		}
	}
	return stack.top()->data;
}
