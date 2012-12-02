#pragma once
#include <iostream>
using namespace std;

template<class T>
class List
{
public:
	class Node;
	List(void)
	{
		_head = new Node;
		//_end = new Node;
		//_head->next = _end;
		//_end->prev = _head;
	}

	~List(void)
	{
	}

	//Node* append(T data)
	//{
	//	Node* node = new Node(data);
	//	node->prev = _end->prev;
	//	node->next = _end;
	//	_end->prev = node;

	//	return node;
	//}

	Node* insert(Node* pNode, T data)
	{
		if (pNode)
		{
			Node* node = new Node(data);

			Node* pNext = pNode->next;
			pNode->next = node;
			node->prev = pNode;
			node->next = pNext;
			pNext->prev = node;

			return node;
		}
		return NULL;
	}

	Node* begin(){return _head;}
	//Node* end(){return _end;}
private:
	class Node
	{
	public:
		Node()
		{
			prev = NULL;
			next = NULL;
		}
		Node(T value)
		{
			data = value;
		}

		Node* prev;
		Node* next;

		T data;
	};

	Node* _head;
	//Node* _end;
};