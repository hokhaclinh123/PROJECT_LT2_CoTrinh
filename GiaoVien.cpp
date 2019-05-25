#include "GiaoVien.h"
//phuong thuc lay gia tri:
string GiaoVien::getDiachi()
{
	return this->sDiaChi;
}
string GiaoVien::getSDT()
{
	return this->sSDT;
}
//phuong thuc cap nhat gia tri:
void GiaoVien::setDiachi(string sDiaChi)
{
	this->sDiaChi = sDiaChi;
}
void GiaoVien::setSDT(string sSDT)
{
	this->sSDT = sSDT;
}
void GiaoVien::setGiaoVien(string sDiaChi, string sSDT)
{
	this->sDiaChi = sDiaChi;
	this->sSDT = sSDT;
}
void GiaoVien::outputBanDoc()
{
	cout << "***THONG TIN BAN DOC GIAO VIEN*****\n";
	BanDoc::xuatBD();
	cout << "Dia chi: " << this->sDiaChi << endl;
	cout << "SDT: " << this->sSDT << endl;
	cout << "-----------------------------------\n";
}
void GiaoVien::readBanDoc(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaBD, ';');
	rewind(stdin);
	getline(file, this->sHoTen, ';');
	rewind(stdin);
	getline(file, this->sKhoa, ';');
	rewind(stdin);
	getline(file, this->sDiaChi, ';');
	rewind(stdin);
	getline(file, this->sSDT);
}
void GiaoVien::writeBanDoc(ofstream &file)
{
	file << this->nLoaiBD << ";" << this->sMaBD << ";"<< this->sHoTen << ";" << this->sKhoa << ";" << this->xNgayDK.getNgay() << ";" << this->xNgayDK.getThang() << ";" << this->xNgayDK.getNam()
		<< ";" << this->sDiaChi << ";" << this->sSDT << endl;
}