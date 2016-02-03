#pragma once

#include<iostream>
#include "Queue.h"
using namespace std;

template<typename T>
class Stack
{
private:
	int nStackSize;
	Node<T>* pFirst;
public:
	Stack()
	{
		pFirst = NULL;
		nStackSize = 0;
	}

	Stack(Stack& Cl_input)
	{
		this->pFirst = Cl_input.pFirst;
		this->nStackSize = Cl_input.nStackSize;
	}

	void fnPush(T tInput)
	{
		if(nStackSize == 0)
		{
			pFirst = new Node<T>;
			pFirst->pNext = NULL;
			pFirst->tData = tInput;

			nStackSize++;

			return;
		}

		Node<T>* p = pFirst;
		for(int i = 0; i < nStackSize-1; i++)
			p = p->pNext;

		p->pNext = new Node<T>;
		p->pNext->pNext = NULL;
		p->pNext->tData = tInput;

		nStackSize++;
	}

	T fnPop()
	{
		if(nStackSize == 0)
			return false;

		Node<T>* p = pFirst;
		for(int i = 0; i < nStackSize-1; i++)
			p = p->pNext;

		T tReturn = p->tData;

		delete p;

		nStackSize--;

		return tReturn;
	}

	T fnTop()
	{
		if(nStackSize == 0)
			return false;

		Node<T>* p = pFirst;
		for(int i = 0; i < nStackSize-1; i++)
			p = p->pNext;

		return p->tData;
	}
	
	bool fnSearch(int tInput) // tInput이 stack에 있는지 탐색
	{
		Node<T>* p = pFirst;
		for (int i = 0; i < nStackSize; i++)
		{
			if (p->tData == tInput)
				return true;

			p = p->pNext;
		}

		return false; // 일치하는 데이터가 없으면 false 반환
	}

	void fnAllDelete() // Stack 전체 삭제
	{
		for(int i = 0; i < nStackSize; i++)
		{
			Node<T>* p = pFirst;
			for(int i = 0; i < nStackSize-1; i++)
				p = p->pNext;
			
			delete p->pNext;
		}

		pFirst = NULL;

		nStackSize = 0;
	}

	T fnStackSize() // Stack 개수 반환
	{
		return nStackSize;
	}
};
