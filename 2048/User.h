#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Map.h"
using namespace std;

class CUser
{
private:
	ClMap<string, string> UserInfor;
public:
	CUser();
	~CUser();
public:
	void fnInsert(string ID, string PW);
	string fnJoin(); // 회원가입
	string fnLogIn(); // 로그인
	ClMap<string, string> fn_getUserInfor();
};
