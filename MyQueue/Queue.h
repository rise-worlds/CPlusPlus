#pragma once

template<class T>
class Queue
{
public:
	class Node;
	Queue()
	{
		front = new Node;
		rear = front;

		_count = 0;
	}

	bool isEmpty() { return rear == front; }
	unsigned int count() { return _count; }

	void push(T data)
	{
		Node* node = new Node(data);
		rear->next = node;
		rear = node;
		_count++;
	}

	Node* pop()
	{
		if (isEmpty())
		{
			return 0;
		}

		Node* node = front->next;
		front->next = node->next;
		_count--;

		if (node == rear)
		{
			rear = front;
		}
		return node;
	}
protected:
private:
	Node* front;
	Node* rear;

	unsigned int _count;
};

template<class T>
class Queue<T>::Node
{
public:
	Node()
	{
		next = 0;
	}
	Node(T value)
	{
		data = value;
	}
	T data;
	Node* next;
};