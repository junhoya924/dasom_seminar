#pragma once

#include "Pair.h"

template <typename Cl_keyType, typename Cl_valueType>
class ClMap
{
private:
	ClPair<Cl_keyType, Cl_valueType>* pPairs;
	int cPairs;
public:
	ClMap();							// 기본생성자
	void insert(ClPair<Cl_keyType, Cl_valueType>& Cl_element);	// ClMap에 parameter로 넣어준 ClPair를 insert
	Cl_valueType& at(Cl_keyType Cl_key);				// ClPair.first()가 Cl_key인 ClPair.second를 return
	bool empty();							// ClMap이 비어있다면 true를 return
	int size() { return cPairs; }					// ClMap의 크기를 return
	Cl_valueType& operator[](Cl_keyType Cl_key);			// ClPair.first()가 Cl_key인 ClPair.second를 return
	void operator=(ClMap<Cl_keyType, Cl_valueType> Cl_Map);		// Map2 = Map1이면 Map2의 내용이 Map1가 같아짐
};

template <typename Cl_keyType, typename Cl_valueType>
ClMap<Cl_keyType, Cl_valueType>::ClMap()
{
	pPairs = NULL;
	cPairs = 0;
}

template <typename Cl_keyType, typename Cl_valueType>
void ClMap<Cl_keyType, Cl_valueType>::insert(ClPair<Cl_keyType, Cl_valueType>& Cl_element)
{
	for(int i = 0; i < cPairs; i++)
		if(pPairs[i].first() == Cl_element.first())
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}

	ClPair<Cl_keyType, Cl_valueType>* pTempPairs = pPairs;

	cPairs++;
	pPairs = new ClPair<Cl_keyType, Cl_valueType>[cPairs];

	for(int i = 0; i < cPairs-1; i++)
		pPairs[i] = pTempPairs[i];
	pPairs[cPairs-1] = Cl_element;

	delete[] pTempPairs;
}

template <typename Cl_keyType, typename Cl_valueType>
Cl_valueType& ClMap<Cl_keyType, Cl_valueType>::at(Cl_keyType Cl_key)
{
	for(int i = 0; i < cPairs; i++)
	{
		if(pPairs[i].first() == Cl_key)
			return pPairs[i].second();
	}
	
	ClPair<Cl_keyType, Cl_valueType> Cl_newPair;
	Cl_newPair.first() = Cl_key;
	insert(Cl_newPair);

	return pPairs[cPairs - 1].second();
}

template <typename Cl_keyType, typename Cl_valueType>
bool ClMap<Cl_keyType, Cl_valueType>::empty()
{
	if(cPairs == 0)
		return true;
	else
		return false;
}

template <typename Cl_keyType, typename Cl_valueType>
Cl_valueType& ClMap<Cl_keyType, Cl_valueType>::operator[](Cl_keyType Cl_key)
{
	for(int i = 0; i < cPairs; i++)
	{
		if(pPairs[i].first() == Cl_key)
			return pPairs[i].second();
	}

	ClPair<Cl_keyType, Cl_valueType> Cl_newPair;
	Cl_newPair.first() = Cl_key;
	insert(Cl_newPair);

	return pPairs[cPairs - 1].second();
}

template <typename Cl_keyType, typename Cl_valueType>
void ClMap<Cl_keyType, Cl_valueType>::operator=(ClMap<Cl_keyType, Cl_valueType> Cl_Map)
{
	cPairs = Cl_Map.cPairs;

	delete[] pPairs;
	pPairs = new ClPair<Cl_keyType, Cl_valueType>[cPairs];
	for(int i = 0; i < cPairs; i++)
		pPairs[i] = Cl_Map.pPairs[i];
}
