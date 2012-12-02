#include "List.h"

int main(char* args)
{
	List<int> list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.append(6);

	List<int>::Node* iter = list.begin();
	do
	{
		iter = iter->next;
		cout << iter->data << endl;
	}while (iter != list.end());

	return 0;
}