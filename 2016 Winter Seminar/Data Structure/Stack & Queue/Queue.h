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
	
	bool fnSearch(T tInput) // tInput�� stack�� �ִ��� Ž��
	{
		Node<T>* p = pFirst;
		for (int i = 0; i < nQueueSize; i++)
		{
			if (p->tData == tInput)
				return true;

			p = p->pNext;
		}

		return false; // ��ġ�ϴ� �����Ͱ� ������ false ��ȯ
	}

	void fnAllDelete() // Queue ��ü ����
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

	T fnQueueSize() // Queue ���� ��ȯ
	{
		return nQueueSize;
	}
};
