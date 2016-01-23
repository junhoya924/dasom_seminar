#include "LinkedList.h"

int main()
{
	CLinkedList<int> list;
	CLinkedList<int>::iterator it;
	
	for (int i = 0; i < 5; i++)
	{
		list.push_front(i + 1);
		it = list.begin();
		//cout << *(it) << endl;;
		cout << list.GetAt(1) << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		list.pop_front();
	}
	if (list.empty())
	{
		cout << "list가 비어있습니다." << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		list.push_back(i + 1);
		cout << list.GetAt(i + 1) << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		list.pop_back();
	}
	if (list.empty())
	{
		cout << "list가 비어있습니다." << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		list.push_back(2*(i + 1));
 		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;
	list.insertAt(3, 2);
	
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;
	list.erase(2, 4);
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;
	list.insertAt(2, 3);
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;
	
	list.remove(2);
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;

	list.clear();
	if (list.empty())
	{
		cout << "list가 비어있습니다." << endl;
	}
	list.push_front(1);
	list.push_front(3);
	list.push_front(2);
	list.push_front(4);

	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;

	list.sort();
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.GetAt(i + 1) << endl;
	}
	cout << endl;
	return 0;
}
