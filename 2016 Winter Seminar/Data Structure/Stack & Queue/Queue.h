#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Queue
{
private:
	int nQueueSize;
	vector<T> vQueue;
public:
	Queue()
	{
		nQueueSize = 0;
	}

	void fnEnQueue(T inputData)
	{
		vQueue.push_back(inputData);
		nQueueSize++;
		return;
	}

	T fnDeQueue()
	{
		T temp = vQueue[0]; // 처음으로 들어온 데이터
		vQueue.erase(vQueue.begin());

		return temp;
	}
	
	bool fnSearch(int iData) // iData가 stack에 있는지 탐색
	{
		int i;
		for (i = 0; i < nQueueSize; i++)
		{
			if (vQueue[i] == iData)
			{
				return true;
			}
		}

		if (i == nQueueSize) // 일치하는 데이터가 없으면 false 반환
		{
			return false;
		}
	}

	void fnAllDelete() // Stack 전체 삭제
	{
		for (int i = 0; i < nQueueSize; i++)
		{
			vQueue.pop_back();
		}

		return;
	}

	T fnQueueSize() // Stack 개수 반환
	{
		return nQueueSize;
	}
};
