#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once
class Admin
{
private: string sUser, sPassword;
public:
	Admin()
	{
		this->sUser = " ";
		this->sPassword = " ";
	}
	Admin(string sUser, string sPassword)
	{
		this->sUser = sUser;
		this->sPassword = sPassword;
	}
	//phuong thuc lay gia tri:
	string getUser();
	string getPassWord();
	//phuong thuc cap nhat gia tri:
	void setUser(string sUser);
	void setPassword(string sPassword);
	void setAdmin(string sUser, string sPassword);
	//doc file:
	void readAdmin(ifstream &fcin);
	~Admin(void){}
};

