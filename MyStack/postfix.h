// Postfix Expression
#pragma once

#include <vector>
using namespace std;

bool isoperator(char op);						  // �ж��Ƿ�Ϊ�����
int priority(char op);						  	  // ����������ȼ�
void postfix(char pre[] , char post[],int &n);    // ����׺���ʽת��Ϊ��׺���ʽ
double read_number(char str[],int *i);			  // �������ַ���ת�����Ӧ������
double postfix_value(char post[]);				  // �ɺ�׺���ʽ�ַ���������Ӧ����ֵ���ʽ��ֵ	
