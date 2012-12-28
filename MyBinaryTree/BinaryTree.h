#pragma once

template<class T>
class BinaryTree
{
public:
	class Node;
	BinaryTree()
	{
		m_pRoot = NULL;
	}

	Node* root() { return m_pRoot; }

	Node* insert(Node* pRoot, T value)
	{
		Node* pNode = new Node(value);

		if (pRoot == NULL)
		{
			return pNode;
		}
		else
		{
			Node* pCurrent = pRoot;
			Node* pBack = NULL;
			while (pCurrent != NULL)
			{
				pBack = pCurrent;
				if (pCurrent->data > value)
				{
					pCurrent = pCurrent->left;
				}
				else
				{
					pCurrent = pCurrent->right;
				}
			}
			if (pBack->data > value)
			{
				pBack->left = pNode;
			}
			else
			{
				pBack->right = pNode;
			}
		}

		return pRoot;
	}

	void setData(T* data, UINT count)
	{
		if (data == NULL) return;

		//Node* pRoot = NULL;
		for (UINT i = 0; i < count; i++)
		{
			m_pRoot = insert(m_pRoot, data[i]);
		}

		//m_pRoot = pRoot;
	}
private:
	class Node
	{
	public:
		Node(T data)
		{
			//parent = NULL;
			left = NULL;
			right = NULL;

			this->data = data;
		}

		//Node* parent;
		Node* left;
		Node* right;
		T data;
	};

	Node* m_pRoot;
};
