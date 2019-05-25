#pragma once
#include "BanDoc.h"
#include "Date.h"
class GiaoVien :
	public BanDoc
{
private: string sDiaChi, sSDT;
		 int nLoaiBD;
public:
	GiaoVien()
	{
		sDiaChi = " ";
		sSDT = " ";
		this->nLoaiBD = 1;
	}
	//GiaoVien() : BanDoc()
	//{
	//	sDiaChi = " ";
	//	sSDT = " ";
	//	this->nLoaiBD = 1;
	//}
	GiaoVien(string sMaBD, string sHoTen, string sKhoa, string sDiaChi, string sSDT)
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	GiaoVien(int nLoaiBD, string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam, string sDiaChi, string sSDT) 
		: BanDoc(sMaBD, sHoTen,sKhoa,nNgay, nThang, nNam) 
	{
		this->nLoaiBD = 1;
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	//phuong thuc lay gia tri:
	string getDiachi();
	string getSDT();
	//phuong thuc cap nhat gia tri:
	void setDiachi(string sDiaChi);
	void setSDT(string sSDT);
	void setGiaoVien(string sDiaChi, string sSDT);
	void outputBanDoc();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);
	~GiaoVien(void){}
};


