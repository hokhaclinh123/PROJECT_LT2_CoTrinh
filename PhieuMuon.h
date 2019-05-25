#include "BanDoc.h"
#include "Sach.h"
#include <fstream>
#pragma once
class PhieuMuon
{
private: BanDoc xBandoc;
		 Sach xSach;
		 Date xNgaymuon, xNgaytra;
		 static int nTongPM;
		 int nMaPM, nTinhTrang;
public:
	friend Sach;
	friend BanDoc;
	friend Date;
	PhieuMuon()
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTinhTrang = 1;
		xNgaytra = tinhNgayTra();
	}
	PhieuMuon(string sMasach, string sMaBD ) : xSach(sMasach) , xBandoc(sMaBD)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTinhTrang = 1;
		xNgaytra = tinhNgayTra();
	}
	PhieuMuon(string sMasach, string sMaBD, int nA, int nB, int nC, int nD, int nE, int nF) : xSach(sMasach), xBandoc(sMaBD), xNgaymuon(nA, nB, nC), xNgaytra(nD, nE, nF)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTinhTrang = 1;
		xNgaytra = tinhNgayTra();
	}
	//phuong thuc lay gia tri:
	BanDoc getBanDoc();
	Sach getSach();
	Date getNgayMuon();
	Date getNgayTra();
	int getMaPM();
	int getTinhTrang();
	//phuong thuc cap nhat gia tri:
	void setBanDocPM(BanDoc xBD);
	void setSachPM(Sach xS);
	void setTinhTrang(int nTinhTrang);
	//bien tinh:
	static int getTongPM()
	{
		return nTongPM;
	}
	//ham xuat , doc , ghi:
	void outputPM();
	void readPM(ifstream &fcin);
	void writePM(ofstream &fcout);
	//ham tinh ngay tra sach:
	Date &tinhNgayTra();
	~PhieuMuon(void) {}
};

