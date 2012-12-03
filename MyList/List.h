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
		_head->prev = _head;
		_head->next = _head;
	}

	~List(void)
	{
		Node* iter = begin();
		while (iter != end())
		{
			remove(iter);
			iter = begin();
		};
	}

	Node* push_front(T data) const
	{
		Node* node = new Node(data);

		node->next			= _head->next;
		node->prev			= _head;
		_head->next->prev	= node;
		_head->next			= node;

		return node;
	}

	Node* push_back(T data) const
	{
		Node* node = new Node(data);
		node->prev          = _head->prev;
		node->next          = _head;
		_head->prev->next	= node;
		_head->prev			= node;

		return node;
	}

	Node* insert(Node* pNode, T data) const
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

	void remove(Node* pNode)
	{
		if (pNode != NULL && pNode != _head)
		{
			pNode->prev->next = pNode->next;
			pNode->next->prev = pNode->prev;
			delete pNode;
			pNode = NULL;
		}
	}

	Node* begin() const
	{
		return _head->next;
	}

	Node* end() const
	{
		return _head;
	}

	bool isEmpty() const
	{
		return _head->next == _head;
	}
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

		~Node()
		{
			prev = NULL;
			next = NULL;
		}

		Node* prev;
		Node* next;

		T data;
	};

	Node* _head;
};