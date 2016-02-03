#pragma once

#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	Node<T>* pNext;
	T tData;
};

template<typename T>
class Queue
{
private:
	int nQueueSize;
	Node<T>* pFirst;
public:
	Queue()
	{
		pFirst = NULL;
		nQueueSize = 0;
	}

	Queue(Queue& Cl_input)
	{
		this->pFirst = Cl_input.pFirst;
		this->nQueueSize = Cl_input.nSize;
	}

	void fnEnQueue(T tInput)
	{
		if(nQueueSize == 0)
		{
			pFirst = new Node<T>;
			pFirst->pNext = NULL;
			pFirst->tData = tInput;

			nQueueSize++;

			return;
		}

		Node<T>* p = pFirst;
		for(int i = 0; i < nQueueSize-1; i++)
			p = p->pNext;

		p->pNext = new Node<T>;
		p->pNext->pNext = NULL;
		p->pNext->tData = tInput;

		nQueueSize++;
	}

	T fnDeQueue()
	{
		if(nQueueSize == 0)
			return false;

		Node<T>* p = pFirst->pNext;
		T tReturn = pFirst->tData;

		delete pFirst;

		pFirst = p;

		nQueueSize--;

		return tReturn;
	}
	
	bool fnSearch(T tInput) // tInput이 stack에 있는지 탐색
	{
		Node<T>* p = pFirst;
		for (int i = 0; i < nQueueSize; i++)
		{
			if (p->tData == tInput)
				return true;

			p = p->pNext;
		}

		return false; // 일치하는 데이터가 없으면 false 반환
	}

	void fnAllDelete() // Queue 전체 삭제
	{
		Node<T>* pTemp = pFirst;
		Node<T>* p = pFirst;
		for(int i = 0; i < nQueueSize; i++)
		{
			pTemp = p->pNext;
			delete p;
			p = pTemp;
		}

		pFirst = NULL;

		nQueueSize = 0;
	}

	T fnQueueSize() // Queue 개수 반환
	{
		return nQueueSize;
	}
};
