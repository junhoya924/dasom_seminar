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
	
	bool fnSearch(int iData) // iData가 stack에 있는지 탐색
	{
		int i;
		for (i = 0; i < nStackSize; i++)
		{
			if (vStack[i] == iData)
			{
				return true;
			}
		}

		if (i == nStackSize) // 일치하는 데이터가 없으면 false 반환
		{
			return false;
		}
	}

	void fnAllDelete() // Stack 전체 삭제
	{
		for (int i = 0; i < nStackSize; i++)
		{
			vStack.pop_back();
		}

		return;
	}

	T fnStackSize() // Stack 개수 반환
	{
		return nStackSize;
	}
};
