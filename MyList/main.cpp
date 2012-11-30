#include "List.h"

int main(char* args)
{
	List<int> list;
	list.insert(list.end(), 1);
	list.insert(list.end(), 2);
	list.insert(list.end(), 3);
	list.insert(list.end(), 4);
	list.insert(list.end(), 5);
	list.insert(list.end(), 6);

	List<int>::Node* iter = list.begin();
	do
	{
		iter = iter->next;
		cout << iter->data << endl;
	}while (iter != list.end());

	return 0;
}