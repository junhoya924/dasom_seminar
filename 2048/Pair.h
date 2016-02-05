#pragma once

#include <string>
using namespace std;

template <typename Cl_firstType, typename Cl_secondType>
class ClPair
{
private:
	Cl_firstType Cl_first;
	Cl_secondType Cl_second;
public:
	ClPair() {}
	ClPair(Cl_firstType Cl_first, Cl_secondType Cl_second);
	Cl_firstType& first() { return Cl_first; }
	Cl_secondType& second() { return Cl_second; }
};

template <typename Cl_firstType, typename Cl_secondType>
ClPair<Cl_firstType, Cl_secondType>::ClPair(Cl_firstType Cl_first, Cl_secondType Cl_second)
{
	this->Cl_first = Cl_first;
	this->Cl_second = Cl_second;
}
