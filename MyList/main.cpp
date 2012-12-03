#include "List.h"

int main(char* args)
{
	List<int>* list = new List<int>;
	List<int>::Node *node = NULL;
	//list->push_back(1);
	//list->push_back(2);
	//list->push_back(3);
	//node = list.push_back(4);
	//list->push_back(5);
	//list->push_back(6);
	//
	//list->insert(node, 7);
	//list->insert(node, 8);

	//list->push_front(1);
	//list->push_front(2);
	//list->push_front(3);
	//node = list.push_front(4);
	//list->push_front(5);
	//list->push_front(6);
	//
	//list->insert(node, 7);
	//list->insert(node, 8);
	//list->remove(node);
	//list->remove(list.begin());

	//list->insert(list->begin(), 1);
	//list->insert(list->begin(), 2);
	//list->insert(list->begin(), 3);

	//list->insert(list->end(), 1);
	//list->insert(list->end(), 2);
	//list->insert(list->end(), 3);

	List<int>::Node* iter = list->begin();
	while (iter != list->end())
	{
		cout << iter->data << endl;
		iter = iter->next;
	};

	delete list;

	return 0;
}