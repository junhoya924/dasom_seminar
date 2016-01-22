#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack
{
private:
	int nStackSize;
	vector<T> vStack;
public:
	Stack()
	{
		nStackSize = 0;
	}

	void fnPush(T inputData)
	{
		vStack.push_back(inputData);
		nStackSize++;
		return;
	}

	T fnPop()
	{
		nStackSize--;
		T temp = vStack[nStackSize];
		vStack.pop_back();

		return temp;
	}

	T fnTop()
	{
		return vStack[nStackSize - 1];
	}
};
