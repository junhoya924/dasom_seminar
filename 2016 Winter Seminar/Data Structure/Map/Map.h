#pragma once

#include "Pair.h"

template <typename Cl_keyType, typename Cl_valueType>
class ClMap
{
private:
	ClPair<Cl_keyType, Cl_valueType>* pPairs;
	int cPairs;
public:
	ClMap();
	void insert(ClPair<Cl_keyType, Cl_valueType>& Cl_element);
	Cl_valueType at(Cl_keyType Cl_key);
	bool empty();
	int size() { return cPairs; }
	Cl_valueType& operator[](Cl_keyType Cl_key);
	void operator=(ClMap<Cl_keyType, Cl_valueType> Cl_Map);
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
Cl_valueType ClMap<Cl_keyType, Cl_valueType>::at(Cl_keyType Cl_key)
{
	for(int i = 0; i < cPairs; i++)
	{
		if(pPairs[i].first() == Cl_key)
			return pPairs[i].second();
	}
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
