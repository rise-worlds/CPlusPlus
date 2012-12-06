
template<class T>
class Stack
{
public:
	class Node;
	Stack()
	{
		_top = NULL;
	}

	void push(T value)
	{
		Node* node = new Node(value);
		if (_top != NULL)
		{
			node->next = _top;
		}
		_top = node;
	}

	Node* pop()
	{
		Node* node = _top;
		if (node != NULL)
		{
			_top = _top->next;
		}
		return node;
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
};