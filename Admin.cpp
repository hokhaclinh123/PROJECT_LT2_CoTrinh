#include "Admin.h"
//phuong thuc lay gia tri:
string Admin::getUser()
{
	return this->sUser;
}
string Admin::getPassWord()
{
	return this->sPassword;
}
//phuong thuc cap nhat gia tri:
void Admin::setUser(string sUser)
{
	this->sUser = sUser;
}
void Admin::setPassword(string sPassword)
{
	this->sPassword = sPassword;
}
void Admin::setAdmin(string sUser, string sPassword)
{
	this->sUser = sUser;
	this->sPassword = sPassword;
}
//doc file:
void Admin::readAdmin(ifstream &fcin)
{
	rewind(stdin);
	getline(fcin, this->sUser, ';');
	rewind(stdin);
	getline(fcin, this->sPassword);
}