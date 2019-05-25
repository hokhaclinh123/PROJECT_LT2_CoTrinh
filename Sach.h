#pragma once
#include "date.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class PhieuMuon;
class Date;
class Sach
{
private: string sMasach, sTuade, sTacgia, sNXB;
		   float fGia;
		   int nNamPhatHanh, nSoTrang;
		   Date xNgayNhapKho;
		   int nTinhTrang;
public:
	friend PhieuMuon;
	friend Date;
	Sach()
	{
		this->sMasach = " ";
		this->sTuade = " ";
		this->sTacgia = " ";
		this->sNXB = "";
		this->fGia = 0.0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrang = 0;
	}
	Sach(string sMaSach) : xNgayNhapKho()
	{
		this->sMasach = sMaSach;
		this->sTuade = " ";
		this->sTacgia = " ";
		this->sNXB = "";
		this->fGia = 0.0;
		this->nNamPhatHanh = 0;
		this->nSoTrang = 0;
		this->nTinhTrang = 0;
	}
	Sach(string sMasach, string sTuade, string sTacgia, string sNXB, float fGia, int nNamPhatHanh, int nSoTrang)
	{
		this->sMasach = sMasach;
		this->sTuade = sTuade;
		this->sTacgia = sTacgia;
		this->sNXB = sNXB;
		this->fGia = fGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
	}
	Sach(string sMasach, string sTuade, string sTacgia, string sNXB, float fGia, int nNamPhatHanh, int nSoTrang,  int nNgay, int nThang, int nNam,int nTinhTrang) : xNgayNhapKho(nNgay,nThang, nNam)
	{
		this->sMasach = sMasach;
		this->sTuade = sTuade;
		this->sTacgia = sTacgia;
		this->sNXB = sNXB;
		this->fGia = fGia;
		this->nNamPhatHanh = nNamPhatHanh;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = nTinhTrang;

	}
	// ham lay gia tri
	string getsMasach();
	string getsTuade();
	string getsTacgia();
	string getsNXB();
	float getfGia();
	int getnNamPhatHanh();
	int getnSoTrang();
	int getnTinhTrang();
	Date getNgayNhapKho();
	// cap nhat gia tri:
	void setsMasach(string sMasach);
	void setsTuade(string sTuade);
	void setsTacgia(string sTacgia);
	void setsNXB(string sNXB);
	void setfGia(float fGia);
	void setnNamPhatHanh(int nNamPhatHanh);
	void setnSoTrang(int nSoTrang);
	void setnTinhTrang(int nTinhTrang);
	void setSach(string sMasach, string sTuade, string sTacgia,
		string sNXB, float fGia, int nNamPhatHanh,
		int nSoTrang, int nTinhTrang);
	// xuat:
	friend ostream& operator<< (ostream &os, Sach &s);
	void output();
	void writeSach(ofstream &fcout);
	void readSach(ifstream &fcin);
	~Sach() {}
};

