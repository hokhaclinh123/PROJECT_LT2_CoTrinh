#pragma once
#include "BanDoc.h"
class SinhVien :
	public BanDoc
{
private: int nKhoaHoc, nLoaiBD;
public:
	SinhVien()
	{
		nKhoaHoc = 0;
		this->nLoaiBD = 2;
	}
	//SinhVien() : BanDoc()
	//{
	//	nKhoaHoc = 0;
	//	this->nLoaiBD = 2;
	//}
	SinhVien(string sMaBD, string sHoTen, string sKhoa, int nKhoaHoc)
	{
		this->nKhoaHoc = nKhoaHoc;
		this->nLoaiBD = 2;
	}
	SinhVien(int nLoaiBD , string sMaBD, string sHoTen, string sKhoa, int nNgay, int nThang, int nNam, int nKhoaHoc) : BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nKhoaHoc = nKhoaHoc;
		this->nLoaiBD = 2;
	}
	int getKhoaHoc();
	void setKhoaHoc(int nKhoaHoc);
	void outputBanDoc();
	void readBanDoc(ifstream &file);
	void writeBanDoc(ofstream &file);
	~SinhVien(void){}
};

