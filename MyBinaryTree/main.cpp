#include <iostream>
#include <windows.h>
#include "BinaryTree.h"

int main(int args, char** argv)
{
	BinaryTree<int>* pTree = new BinaryTree<int>();
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	pTree->setData(data, 15);
	BinaryTree<int>::Node* pRoot = pTree->root();
	
	std::cout << "left node" << std::endl;
	BinaryTree<int>::Node* pNode = pRoot->left;
	while (pNode != NULL)
	{
		std::cout << pNode->data << "   ";
		pNode = pNode->left;
	}
	std::cout << std::endl;

	std::cout << "right node" << std::endl;
	pNode = pRoot->right;
	while (pNode != NULL)
	{
		std::cout << pNode->data << "   ";
		pNode = pNode->left;
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}

