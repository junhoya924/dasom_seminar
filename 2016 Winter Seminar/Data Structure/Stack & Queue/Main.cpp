#include<iostream>
#include"Queue.h"
#include"Stack.h"
using namespace std;

int main()
{
	Stack<int> myStack;
	Queue<int> myQueue;

	int nChoose;
	int nInputData;

	cout << "1. Stack" << endl << endl;
	cout << "Enter Input first Data : ";
	cin >> nInputData;
	myStack.fnPush(nInputData);
	
	cout << "Enter Input second Data : ";
	cin >> nInputData;
	myStack.fnPush(nInputData);

	cout << "Enter Input third Data : ";
	cin >> nInputData;
	myStack.fnPush(nInputData);

	cout << endl;
	cout << "Stack.pop () -> " << myStack.fnPop() << endl;
	cout << "Stack.top() -> " << myStack.fnTop() << endl;
	cout << endl;

	//-----------------------------------------
	cout << "---------------------------------------" << endl << endl;
	cout << "1. Queue" << endl << endl;
	cout << "Enter Input first Data : ";
	cin >> nInputData;
	myQueue.fnEnQueue(nInputData);

	cout << "Enter Input second Data : ";
	cin >> nInputData;
	myQueue.fnEnQueue(nInputData);

	cout << "Enter Input third Data : ";
	cin >> nInputData;
	myQueue.fnEnQueue(nInputData);

	cout << endl;
	cout << "Queue.DeQueue () -> " << myQueue.fnDeQueue() << endl;
	cout << "Queue.DeQueue () -> " << myQueue.fnDeQueue() << endl;
	cout << endl;

	return 0;
}
