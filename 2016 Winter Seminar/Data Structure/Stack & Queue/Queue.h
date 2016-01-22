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
};
