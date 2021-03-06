#pragma once
#include <iostream>
using namespace std;

template <class dataType>
class CDoubleLinkedList
{
private:
	class CNode
	{
	public:
		CNode(dataType i_data)
		{
			data = new dataType;
			*data = i_data;
			pNext = NULL;
		}
		~CNode()
		{
			delete data;
		}
		dataType* data;
		CNode* pNext;
		CNode* pPrev;
	};
	CNode* pHead;
public:
	CDoubleLinkedList()
	{
		pHead = new CNode(0);
		pHead->pNext = NULL;
	}
	~CDoubleLinkedList()
	{
		RemoveAll();
	}
	dataType* GetAt(int i_index);
	void RemoveAt(int i_index);
	void Append(const dataType& i_data);
	void InsertAt(const dataType& i_data, int i_index);
	void RemoveAll();
	int size();
};

template<typename dataType>
dataType* CDoubleLinkedList<dataType>::GetAt(int i_index) //-------예외처리
{
	int cCount = 0;
	CNode* pCur = pHead;

	if (i_index <= size()) //-----
	{
		while (cCount != i_index)
		{
			pCur = pCur->pNext;
			cCount++;
		}
	}
	else
	{
		cout << i_index << "의 위치에서 Get 할 수 없습니다." << endl;
	}

	return pCur->data;
}

template<typename dataType>
void CDoubleLinkedList<dataType>::RemoveAt(int i_index) //----------예외처리
{
	int cCount = 0;
	CNode* pCur = pHead;

	if (i_index <= size()) //-------
	{
		while (cCount != i_index - 1)
		{
			pCur = pCur->pNext;
			cCount++;
		}


		CNode* pTemp = pCur->pNext->pNext;

		delete pCur->pNext;
		pCur->pNext = pTemp;
		pCur->pNext->pPrev = pCur;
	}
	else //--------
	{
		cout << i_index << "의 위치에 Remove 할 수 없습니다." << endl;
	}

	return;
}

template<typename dataType>
void CDoubleLinkedList<dataType>::Append(const dataType& i_data)
{
	CNode* pCur = pHead;

	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
	}

	CNode* newNode = new CNode(i_data);
	pCur->pNext = newNode;
	pCur->pNext->pPrev = pCur;
	pCur->pNext->pNext = NULL;

}

template<typename dataType>
void CDoubleLinkedList<dataType>::InsertAt(const dataType& i_data, int i_index) //-----------예외처리
{
	if (i_index <= size()) //---------
	{
		CNode* pCur = pHead;
		for (int i = 0; i < i_index - 1; i++)
		{
			pCur = pCur->pNext;
		}

		CNode* newNode = new CNode(i_data);
		CNode* pTemp = pCur->pNext;
		pCur->pNext = newNode;
		pCur->pNext->pNext = pTemp;
		pCur->pNext->pPrev = pCur;
		pCur->pNext->pNext->pPrev = pCur->pNext;
	}
	else //---------
	{
		cout << i_index << "의 위치에 insert 할 수 없습니다." << endl;
	}

	return;
}

template<typename dataType>
void CDoubleLinkedList<dataType>::RemoveAll()
{
	CNode* pCur = pHead;
	CNode* pTemp;
	while (pCur->pNext != NULL)
	{
		pTemp = pCur->pNext;
		delete pCur;
		pCur = pTemp;
	}
}

template<typename dataType>
int CDoubleLinkedList<dataType>::size()
{
	CNode* pCur = pHead;
	int cCount = 0;
	while (pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
		cCount++;
	}
	return cCount;
}
