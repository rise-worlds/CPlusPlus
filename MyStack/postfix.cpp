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

//	 ����׺���ʽת��Ϊ��׺���ʽ�����غ�׺���ʽ�ĳ��ȣ������ո�
void postfix(char pre[] ,char post[],int &n)
{
	int i = 0 ,j=0;
	Stack<char> stack;

	stack.push('#');	// ���Ȱѽ�����־��#������ջ��

	while(pre[i]!='#')
	{
		if((pre[i]>='0' && pre[i] <='9')||pre[i] =='.') // �������ֺ�С����ֱ��д���׺���ʽ
		{
			post[j++] = pre[i];
			n++;
		}
		else if (pre[i]=='(')	// �������������ñȽ�ֱ����ջ
			stack.push(pre[i]);
		else if(pre[i] ==')')	// ���������Ž����Ӧ�����ź�Ĳ�������������ջ�еģ�ȫ��д���׺���ʽ
		{
			while(stack.top()->data!='(')
			{
				post[j++] = stack.pop()->data;
				n++;
			}
			stack.pop(); // ����������ջ����׺���ʽ�в���С����
		}
		else if (isoperator(pre[i]))
		{
			post[j++] = ' '; // �ÿո�ֿ�������(
			n++;
			while(priority(pre[i]) <= priority(stack.top()->data)) 
			{
				// ��ǰ�Ĳ�����С�ڵ���ջ�������������ȼ�ʱ����ջ��������д�뵽��׺���ʽ���ظ��˹���
				post[j++] = stack.pop()->data;
				n++;
			}

			stack.push(pre[i]);	// ��ǰ���������ȼ�����ջ�������������ȼ������ò�������ջ
		}

		i++;
	}
	while(stack.top() != NULL) // �����еĲ����������׺���ʽ
	{
		post[j++] = stack.pop()->data;
		n++;
	}
}

double read_number(char str[],int *i)
{
	double x=0.0;
	int k = 0;
	while(str[*i] >='0' && str[*i]<='9')  // ������������
	{
		x = x*10+(str[*i]-'0');
		(*i)++;
	}

	if(str[*i]=='.') // ����С������
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
	Stack<double> stack;	// ������ջ

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
