#include <iostream>
#include "Map.h"
using namespace std;

void main()
{
	ClMap<string, string> Cl_Map1;

	Cl_Map1.insert(ClPair<string, string>("test", "�Ⱦ�"));
	ClPair<string, string> Cl_pair1;
	Cl_pair1.first() = "c++";
	Cl_pair1.second() = "������";
	Cl_Map1.insert(Cl_pair1);
	Cl_Map1["ddong"] = "����";

	string sStr1 = "test";
	string sStr2 = "c++";
	string sStr3 = "ddong";
	cout << Cl_Map1.at(sStr1) << endl;	// �Ⱦ�
	cout << Cl_Map1.at(sStr2) << endl;	// ������
	cout << Cl_Map1.at(sStr3) << endl;	// ����
	cout << Cl_Map1.empty() << endl;	// 0
	cout << Cl_Map1.size() << endl;		// 3

	ClMap<string, string> Cl_Map2;

	cout << Cl_Map2.empty() << endl;	// 1
	cout << Cl_Map2.size() << endl;		// 0

	Cl_Map2 = Cl_Map1;

	cout << Cl_Map2[sStr1] << endl;		// �Ⱦ�
	cout << Cl_Map2[sStr2] << endl;		// ������
	cout << Cl_Map1[sStr3] << endl;		// ����
	cout << Cl_Map2.empty() << endl;	// 0
	cout << Cl_Map2.size() << endl;		// 3

	ClMap<string, string>::iterator Cl_it;

	for(Cl_it = Cl_Map1.begin(); Cl_it <= Cl_Map1.end(); Cl_it++)
		cout << (*Cl_it).first() << " " << (*Cl_it).second() << endl;
	// test �Ⱦ�
	// c++ ������
	// ddong ����

	Cl_it = Cl_Map1.end();
	Cl_Map1.erase(Cl_it);	// no more ddong ����! yeah!

	for(Cl_it = Cl_Map1.begin(); Cl_it <= Cl_Map1.end(); ++Cl_it)
		cout << Cl_it->first() << " " << Cl_it->second() << endl;
	// test �Ⱦ�
	// c++ ������
}