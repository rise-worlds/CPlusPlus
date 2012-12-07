
template<class T>
class Stack
{
public:
	class Node;
	Stack()
	{
		_top = NULL;
		_count = 0;
	}

	void push(T value)
	{
		Node* node = new Node(value);
		if (_top != NULL)
		{
			node->next = _top;
		}
		_top = node;
		_count++;
	}

	Node* pop()
	{
		Node* node = _top;
		if (node != NULL)
		{
			_top = _top->next;
			node->next = NULL;
			_count--;
		}
		return node;
	}

	Node* top()
	{
		return _top;
	}

	unsigned int count()
	{
		return _count;
	}
protected:
	class Node
	{
	public:
		Node(T value)
		{
			next = NULL;
			data = value;
		}
		T data;
		Node* next;
	};
private:
	Node* _top;
	unsigned int _count;
};