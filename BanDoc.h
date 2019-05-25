#ifndef BANDOC_h
#define BANDOC_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Date.h"
class PhieuMuon;
#pragma once
class BanDoc
{
protected: 
	string sMaBD, sHoTen, sKhoa;
	Date xNgayDK;
public:
	friend PhieuMuon;
	friend Date;
	BanDoc()
	{
		this->sMaBD = "";
		this->sHoTen = "";
		this->sKhoa = "";
	}
	BanDoc(string sMaBD) : xNgayDK()
	{
		this->sMaBD = sMaBD;
		sHoTen = "";
		sKhoa = "";
	}
	BanDoc(string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam) : xNgayDK(nNgay,  nThang,  nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	//pt lay gia tri :
	string getMaBD();
	string getHoTen();
	string getKhoa();
		//pt lay gia tri :
	void setMaBD(string sMaBD);
	void setHoTen(string sHoTen);
	void setKhoa(string sKhoa);
	void setBanDoc(string sMaBD, string sHoTen, string sKhoa);
	virtual void outputBanDoc() {};
	virtual void readBanDoc(ifstream &file) {};
	virtual void writeBanDoc(ofstream &file) {};
	void xuatBD();
	virtual ~BanDoc(void){}
};

#endif // !BANDOC_h