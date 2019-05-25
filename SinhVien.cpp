#include "SinhVien.h"
int SinhVien::getKhoaHoc()
{
	return this->nKhoaHoc;
}
void SinhVien::setKhoaHoc(int nKhoaHoc)
{
	this->nKhoaHoc = nKhoaHoc;
}
void SinhVien::outputBanDoc()
{
	cout << "******THONG TIN BAN DOC SINH VIEN********\n";
	BanDoc::xuatBD();
	cout << "Khoa hoc: " << this->nKhoaHoc << endl;
	cout << "-----------------------------------------\n";
}
void SinhVien::readBanDoc(ifstream &file)
{
	rewind(stdin);
	getline(file, this->sMaBD, ';');
	rewind(stdin);
	getline(file, this->sHoTen, ';');
	rewind(stdin);
	getline(file, this->sKhoa, ';');
	file >> this->nKhoaHoc;
}
void SinhVien::writeBanDoc(ofstream &file)
{
	file << this->nLoaiBD << ";" << this->sMaBD << ";" << this->sHoTen << ";" << this->sKhoa << ";" << this->xNgayDK.getNgay() << ";" << this->xNgayDK.getThang() 
		<< ";" << this->xNgayDK.getNam() << ";" << this->nKhoaHoc << endl;
}
