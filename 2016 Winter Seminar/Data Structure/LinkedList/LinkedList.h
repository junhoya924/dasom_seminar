#pragma once
#include <iostream>
using namespace std;

template <class dataType>
class CNode
{
public:
	dataType data;
	CNode* pNext;
public:
	CNode(dataType i_data = NULL)
	{
		data = i_data;
	}

	//dataType operator*() { return *pData; }
};

template <class dataType>
class CIterator
{
private:
	CNode<dataType>* pNode;
public:
	CIterator(CNode<dataType>* pNode = NULL) { this->pNode = pNode; } 
	CIterator(const CIterator &i_iterator) { this->pNode = i_iterator.pNode; } 
	void operator=(CIterator i_iterator) { this->pNode = i_iterator.pNode; }
	dataType& operator *() { return pNode->data; } 
	CNode<dataType>* operator->() { return pNode; } 
	const bool operator ==(CIterator<dataType> i_iterator) { return this->pNode == i_iterator.pNode; }
	const bool operator !=(CIterator<dataType> i_iterator) { return this->pNode != i_iterator.pNode; }
	const CIterator& operator++() //전위
	{
		if (pNode != NULL)
		{
			pNode = pNode->pNext;
		}
		return *this;
	}
	const CIterator& operator++(int) // 후위
	{
		if (pNode != NULL)
		{
			CIterator Cl_temp = new CIterator(*this);
			pNode = pNode->pNext;
		}
		return *Cl_temp;
	}
	/*ostream& operator<<(CIterator<dataType> i_iterator)
	{
	return *i_iterator;
	}*/
};


template <class dataType>
class CLinkedList
{
private:
	CNode<dataType>* pHead;
public:
	typedef CIterator<dataType>* iterator;
public:
	CLinkedList()
	{
		pHead = NULL;
	}
	~CLinkedList()
	{
		clear();
	}
	dataType GetAt(int i_index);                       //index위치의 값을 가져온다.     
	iterator begin()                                     //첫번째 위치를 가리킨다
	{
		return iterator(pHead);
	}
	iterator end()                                       //마지막 위치의 다음을 가리킨다
	{
		CNode<dataType>* pCur = pHead;
		while (pCur != NULL)
		{
			pCur = pCur->pNext;
		}
		return iterator(pCur);
	}
	dataType front();                                   //첫번째 데이터의 참조 반환
	dataType back();                                    //마지막 데이터의 참조 반환
	void push_front(const dataType& i_data);            //첫번째 위치에 데이터 추가
	void pop_front();                                   //첫번째 위치의 데이터 삭제
	void push_back(const dataType& i_data);             //마지막 위치에 데이터 추가
	void pop_back();                                    //마지막 위치의 데이터 삭제
	void insertAt(const dataType& i_data, int i_index); //인덱스위치에 데이터 추가
	void clear();                                       //저장하고 있는 모든 데이터 삭제
	bool empty();                                       //저장 데이터 유/무, 없으면 true반환
	int size();                                         //저장하고 있는 개수 반환
	void erase(int i_index1, int i_index2);             //지정된 범위에 있는 데이터 삭제
	void remove(const dataType& i_data);                //지정된 값과 일치하는 모든 데이터 삭제
	void sort();                                        //데이터 들을 정렬
};

template <class dataType>
dataType CLinkedList<dataType>::GetAt(int i_index)
{
	int cCount = 1;
	CNode<dataType>* pCur = pHead;

	while (cCount != i_index && pCur->pNext != NULL)
	{
		pCur = pCur->pNext;
		cCount++;
	}

	return pCur->data;
}

template <class dataType>
dataType CLinkedList<dataType>::front()
{
	return pHead->data;
}

template <class dataType>
dataType CLinkedList<dataType>::back()
{
	CNode<dataType>* pCur = pHead;
	while (pCur->next != NULL)
	{
		pCur = pCur->pNext;
	}
	return pCur->data;
}

template <class dataType>
void CLinkedList<dataType>::push_front(const dataType& i_data)
{
	if (pHead == NULL)
	{
		pHead = new CNode<dataType>(i_data);
		pHead->pNext = NULL;
	}
	else
	{
		CNode<dataType>* Cl_newNode = new CNode<dataType>(i_data);
		Cl_newNode->pNext = pHead;
		pHead = Cl_newNode;
	}
}

template <class dataType>
void CLinkedList<dataType>::pop_front() // --------------예외처리
{
	if (pHead != NULL)
	{
		CNode<dataType>* pCur = pHead->pNext;
		delete pHead;
		pHead = pCur;
	}
	else // 리스트가 비었을 경우
	{
		cout << "List가 비어있습니다." << endl;
	}

	return;
}

template <class dataType>
void CLinkedList<dataType>::push_back(const dataType& i_data)
{
	if (pHead == NULL)
	{
		pHead = new CNode<dataType>(i_data);
		pHead->pNext = NULL;
	}
	else
	{
		CNode<dataType>* pCur = pHead;
		while (pCur->pNext != NULL)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = new CNode<dataType>(i_data);
		pCur->pNext->pNext = NULL;
	}
}

template <class dataType>
void CLinkedList<dataType>::pop_back() //----------예외처리
{
	if (pHead == NULL) // 아무것도 없을 때
	{
		cout << "List가 비어있습니다." << endl;
	}
	else if (pHead->pNext == NULL)
	{
		delete pHead;
		pHead = NULL;
	}
	else
	{
		CNode<dataType>* pCur = pHead;
		while (pCur->pNext->pNext != NULL)
		{
			pCur = pCur->pNext;
		}
		delete pCur->pNext;
		pCur->pNext = NULL;
	}
}

template <class dataType>
void CLinkedList<dataType>::insertAt(const dataType& i_data, int i_index) // --------예외처리
{
	if (i_index == 1)
	{
		push_front(i_data);
	}
	else if (i_index > 1)
	{
		if (i_index < size()) //-----
		{
			CNode<dataType>* pCur = pHead;
			for (int i = 0; i < i_index - 2; i++)
			{
				pCur = pCur->pNext;
			}

			CNode<dataType>* pTemp = pCur->pNext;
			pCur->pNext = new CNode<dataType>(i_data);
			pCur->pNext->pNext = pTemp;
		}
		else if (i_index == size()) //-----
		{
			push_back(i_data);
		}
		else //------
		{
			cout << i_index << "의 위치에 insert 할 수 없습니다." << endl;
		}
	}

	return;
}

template <class dataType>
void CLinkedList<dataType>::clear()
{
	CNode<dataType>* pCur = pHead;
	CNode<dataType>* pTemp;
	while (pCur != NULL)
	{
		pTemp = pCur->pNext;
		delete pCur;
		pCur = pTemp;
	}
	pHead = NULL;
}

template <class dataType>
bool CLinkedList<dataType>::empty()
{
	return pHead == NULL;
}

template <class dataType>
int CLinkedList<dataType>::size()
{
	CNode<dataType>* pCur = pHead;
	int cCount = 0;
	while (pCur != NULL)
	{
		pCur = pCur->pNext;
		cCount++;
	}
	return cCount;
}

template <class dataType>
void CLinkedList<dataType>::erase(int i_index1, int i_index2)
{
	CNode<dataType>* pCur = pHead;
	CNode<dataType>* pTemp1 = NULL;
	CNode<dataType>* pTemp2 = NULL;
	int cCount = 0;
	while (pCur != NULL && cCount != i_index1 - 2)
	{
		pCur = pCur->pNext;
		cCount++;
	}
	pTemp1 = pCur;
	pCur = pCur->pNext;
	for (int i = 0; i < (i_index2 - i_index1 + 1); i++)
	{
		pTemp2 = pCur->pNext;
		delete pCur;
		pCur = pTemp2;
	}
	pTemp1->pNext = pCur;

}

template <class dataType>
void CLinkedList<dataType>::remove(const dataType& i_data)
{
	CNode<dataType>* pCur = pHead;
	while (pHead != NULL && pCur->pNext != NULL)
	{
		if (pHead->data == i_data)
		{
			pop_front();
			pCur = pHead;
		}
		else
		{
			CNode<dataType>* pTemp = NULL;
			if (pCur->pNext->data == i_data)
			{
				pTemp = pCur->pNext->pNext;
				delete pCur->pNext;
				pCur->pNext = pTemp;
			}
			else
			{
				pCur = pCur->pNext;
			}
		}
	}

}

template <class dataType>
void CLinkedList<dataType>::sort()
{
	CNode<dataType>* pCur = pHead->pNext;

	while (pCur != NULL)
	{
		for (CNode<dataType>* pTemp = pHead; pTemp != pCur; pTemp = pTemp->pNext)
		{
			if (pTemp->data > pCur->data)
			{
				dataType dTemp = pTemp->data;
				pTemp->data = pCur->data;
				pCur->data = dTemp;
			}
		}
		pCur = pCur->pNext;
	}
}
