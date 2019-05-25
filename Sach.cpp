
#include "Sach.h"
// ham lay gia tri
string Sach::getsMasach()
{
	return sMasach;
}
string Sach::getsTuade()
{
	return sTuade;
}
string Sach::getsTacgia()
{
	return sTacgia;
}
string Sach::getsNXB()
{
	return sNXB;
}
float Sach::getfGia()
{
	return fGia;
}
int Sach::getnNamPhatHanh()
{
	return nNamPhatHanh;
}
int Sach::getnSoTrang()
{
	return nSoTrang;
}
int Sach::getnTinhTrang()
{
	return nTinhTrang;
}
Date Sach::getNgayNhapKho()
{
	return this->xNgayNhapKho;
}
// cap nhat gia tri:
void Sach::setsMasach(string sMasach)
{
	this->sMasach = sMasach;
}
void Sach::setsTuade(string sTuade)
{
	this->sTuade = sTuade;
}
void Sach::setsTacgia(string sTacgia)
{
	this->sTacgia = sTacgia;
}
void Sach::setsNXB(string sNXB)
{
	this->sNXB = sNXB;
}
void Sach::setfGia(float fGia)
{
	this->fGia = fGia;
}
void Sach::setnNamPhatHanh(int nNamPhatHanh)
{
	this->nNamPhatHanh = nNamPhatHanh;
}
void Sach::setnSoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}
void Sach::setnTinhTrang(int nTinhTrang)
{
	this->nTinhTrang = nTinhTrang;
}
void Sach::setSach(string sMasach, string sTuade, string sTacgia,
	string sNXB, float fGia, int nNamPhatHanh,
	int nSoTrang, int nTinhTrang)
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
// xuat TT Sach:
ostream& operator<< (ostream &os, Sach &s)
{
	os << s.sMasach << ";" << s.sTuade << ";" << s.sTacgia << ";" << s.sNXB << ";" << s.fGia << ";" << s.nNamPhatHanh
		<< ";" << s.nSoTrang << ";" << s.xNgayNhapKho.getNgay() << ";" << s.xNgayNhapKho.getThang() << ";" << s.xNgayNhapKho.getNam() << s.nTinhTrang << endl;
	return os;
}
void Sach::writeSach(ofstream &fcout)
{
	fcout << this->sMasach << ";" << this->sTuade << ";" << this->sTacgia << ";" << this->sNXB << ";" << this->fGia << ";" << this->nNamPhatHanh
		<< ";" << this->nSoTrang << ";" << this->xNgayNhapKho.nNgay << ";" << this->xNgayNhapKho.nThang << ";" << this->xNgayNhapKho.nNam << ";" << this->nTinhTrang << endl;
}
void Sach::readSach(ifstream &fcin)
{
	rewind(stdin);
	getline(fcin, this->sMasach, ';');
	rewind(stdin);
	getline(fcin, this->sTuade, ';');
	rewind(stdin);
	getline(fcin, this->sTacgia, ';');
	rewind(stdin);
	getline(fcin, this->sNXB, ';');
	fcin >> this->fGia;
	fcin.ignore(1);
	fcin >> this->nNamPhatHanh;
	fcin.ignore(1);
	fcin >> this->nSoTrang;
	fcin.ignore(1);
	fcin >> this->xNgayNhapKho.nNgay;
	fcin.ignore(1);
	fcin >> this->xNgayNhapKho.nThang;
	fcin.ignore(1);
	fcin >> this->xNgayNhapKho.nNam;
	fcin.ignore(1);
	fcin >> this->nTinhTrang;
	fcin.ignore(1, '\n');
}
void Sach::output()
{
	cout << "************THONG TIN SACH****************\n";
	cout << "Ma sach: " << this->sMasach << endl;
	cout << "Tua de: "  << this->sTuade << endl;
	cout << "Tac gia: " << this->sTacgia << endl;
	cout << "Nha xuat ban:"  << this->sNXB << endl;
	cout << "Tri gia: "  << this->fGia << endl;
	cout << "Nam phat hanh: "  << this->nNamPhatHanh << endl;
	cout << "So trang: "  << this->nSoTrang << endl;
	cout << "Ngay nhap kho: "; xNgayNhapKho.print();
	cout << "Tinh trang sach: " << this->nTinhTrang << endl;
	cout << "---------------------------------------------\n";
}
