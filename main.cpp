//thu vien:
#include "Admin.h"
#include "BanDoc.h"
#include "Sach.h"
#include "PhieuMuon.h"
#include "Date.h"
#include "GiaoVien.h"
#include "SinhVien.h" 
#include <vector>
//khai bao nguyen mau ham con:
 //mau va ma hoa pass:
void Color(int nX);
string passwordInput(unsigned maxLength);
//Menu:
void MenuChinh();
void MenuQuanLy();
void MenuTimKiemTT();
void MenuPhieuMuon();
void MenuBanDoc();
void MenuThemBanDoc();
void MenuSach();
void MenuThongKe();
//SACH:
void docDSSach(vector <Sach> &p);
void xuatDSSach(vector <Sach> p);
void ghiDSSach(vector <Sach> &p);
void xoaSach(vector <Sach> &p, string sMaSach);
void themSach(vector <Sach> &p);
int nDemSachDangMuon(vector <Sach> p);
int nDemSachConLai(vector <Sach> p);
void timkiemSach(vector <Sach> p, string sMaSach);
bool kiemtraSach(vector <Sach> p, string sMaSach);
//BAN DOC:
void docDSBanDoc(vector <BanDoc*> &b);
void xuatDSBanDoc(vector <BanDoc*> b);
void ghiDSBanDoc(vector <BanDoc*> &b);
int nDemSLBanDocGV(vector <BanDoc*> b);
int nDemSLBanDocSV(vector <BanDoc*> b);
void themBanDoc(vector <BanDoc*> &b);
void timkiemBanDoc(vector <BanDoc*> b, string sMaBD);
bool kiemtraBanDoc(vector <BanDoc*> b, string sMaBD);
//PHIEU MUON:
void docDSPhieuMuon(vector <PhieuMuon> &M);
void xuatDSPhieuMuon(vector <PhieuMuon> M);
void ghiDSPhieuMuon(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p);
void taoPhieuMuon(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p);
int nDemPhieuMuon(vector <PhieuMuon> M);
void traSach(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p);
void lietKeSachMaBanDocDangMuon(vector <PhieuMuon> M, vector <Sach> p);
//ADMIN:
void docDSAdmin(vector <Admin> &A);
void dangnhapAdmin(vector <Admin> A);
//Cac Chuc Nang:
void CN_TimKiemTT();
void CN_QuanLySach();
void CN_QuanLyBanDoc();
void CN_QuanLyPhieuMuon();
void CN_ThongKe();
//khai bao bien toan cuc:
int PhieuMuon::nTongPM = 0;
int nChon = 0, nN = 0, nVT = 0, nLoaiBD = 0;
int nLoaiTimKiem = 0, nQuanLySach = 0, nQuanLyBanDoc = 0, nQuanLyPhieuMuon = 0, nQL = 0, nThongKe = 0;
string sMaSach = " ", sMaBD = " ";
vector <Sach> p;
vector <BanDoc*> b;
vector <PhieuMuon> M;
vector <Admin> A;
//chuong trinh chinh:
void main()
{
	docDSSach(p);
	docDSBanDoc(b);
	docDSPhieuMuon(M);
	docDSAdmin(A);
	do
	{
		system("cls");
		MenuChinh();
		cout << "Chon Chuc Nang So: "; cin >> nChon;
		switch (nChon)
		{
		case 1: // hien thi thong tin sach:
		{
			Color(14);
			xuatDSSach(p);
			break;
		}
		case 2: //hien thi thong tin ban doc
		{
			Color(14);
			xuatDSBanDoc(b);
			break;
		}
		case 3: //tim kiem thong tin sach va ban doc
		{
			CN_TimKiemTT();
			break;
		}
		case 4: //Quan Ly
		{
			dangnhapAdmin(A);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			system("pause");
			exit(1);
			break;
		}
		system("pause");
	} while (nChon >= 1 || nChon <= 4);
}
//dinh nghia nguyen mau ham con:
//  ADMIN:
void dangnhapAdmin(vector <Admin> A)
{
	int flag = 0, i = 1;
	string sUser = " ", sPass = " ";
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\t    DANG NHAP\t\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "Nhap UserName: "; rewind(stdin); getline(cin, sUser);
	cout << "Nhap PassWord: "; rewind(stdin); sPass = passwordInput(6);
	for (int i = 0; i < A.size(); i++)
	{
		if (sUser == A[i].getUser() && sPass == A[i].getPassWord())
		{
			flag = 1;
			cout << "Dang Nhap Thanh Cong!\n";
			while (true)
			{
				do
				{
					system("cls");
					MenuQuanLy();
					cout << "Vui Long Chon Chuc Nang Quan Ly: "; cin >> nQL;
					switch (nQL)
					{
					case 1: // chuc nang quan ly Phieu Muon:
					{
						CN_QuanLyPhieuMuon();
						break;
					}
					case 2: // chuc nang quan ly Sach: 
					{
						CN_QuanLySach();
			
						break;
					}
					case 3: // chuc nang quan ly Ban Doc:
					{
						CN_QuanLyBanDoc();
						break;
					}
					case 4: // chuc nang thong ke:
					{
						CN_ThongKe();
						break;
					}
					default:
						Color(13);
						cout << "Ban Chon thoat chuong trinh!\n";
						return;
						break;
					}
				} while (nQL >= 1 || nQL <= 4);
			}
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "Dang Nhap That Bai, Vui Long Dang Nhap Lai!\n";
	}
}
void docDSAdmin(vector <Admin> &A)
{
	ifstream fcin;
	fcin.open("Admin.txt");
	if (fcin.is_open() == true)
		cout << "Doc file thanh cong!\n";
	else
		cout << "Doc file that bai!\n";
	while (fcin.eof() == false)
	{
		Admin xAd;
		xAd.readAdmin(fcin);
		A.push_back(xAd);
	}
	fcin.close();
}
//  PHIEU MUON:
void lietKeSachMaBanDocDangMuon(vector <PhieuMuon> M, vector <Sach> p)
{
	int flag = 0;
	string sMaBD = " ";
	NhapMaBD:
	cout << "Nhap Ma Ban Doc De Liet Ke Sach: ";
	rewind(stdin); getline(cin, sMaBD);
	cout << "\n*********DANH SACH SACH MA BAN DOC DANG MUON*********\n";
	for (int i = 0; i < M.size(); i++)
	{
		if (M[i].getBanDoc().getMaBD() == sMaBD && M[i].getTinhTrang() != 0)
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (p[j].getsMasach() == M[i].getSach().getsMasach())
				{
					flag = 1;
					p[j].output();
				}
			}
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "Ban Doc Nay Chua Muon Sach!\n";
		system("pause");
		goto NhapMaBD;
	}
}
void traSach(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p)
{
	int flag = 0, nMaPM = 0;
	string sMaSach = " ";
	while (true)
	{
		cout << "Nhap Ma Phieu Muon De Tra Sach: "; cin >> nMaPM;
		for (int i = 0; i < M.size(); i++)
		{
			if (M[i].getMaPM() == nMaPM)
			{
				if (M[i].getTinhTrang() != 0)
				{
					flag = 1;
					M[i].setTinhTrang(0); // gan tinh trang cua PM = 0;
					//xu ly tinh trang cua sach:
					sMaSach = M[i].getSach().getsMasach();
					for (int j = 0; j < p.size(); j++)
					{
						if (p[j].getsMasach() == sMaSach)
						{
							p[j].setnTinhTrang(0); // gan tinh trang sach ve 0
							break;
						}
					}
					//ghi du lieu sach va phieu muon:
					ghiDSSach(p);
					ghiDSPhieuMuon(M,b,p);
					cout << "Tra Sach Thanh Cong!\n";
					break;
				}
			}
		}
		if (flag == 0)
		{
			cout << "Ma Phieu Muon Khong Ton Tai!\n";
			system("pause");
		}
		else if (flag == 1)
		{
			break;
		}
	}
}
int nDemPhieuMuon(vector <PhieuMuon> M)
{
	int nDem = 0;
	for (int i = 0; i < M.size(); i++)
	{
		nDem++;
	}
	return nDem;
}
void taoPhieuMuon(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p)
{
	string sMaSach = " ", sMaBD = " ";
	while (true)
	{
		cout << "Nhap Ma Ban Doc: ";
		rewind(stdin); getline(cin, sMaBD);
		if (kiemtraBanDoc(b, sMaBD) == false)
		{
			cout << "Ma Ban Doc Khong Ton Tai!\n";
			system("pause");
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Nhap Ma Sach: ";
		rewind(stdin); getline(cin, sMaSach);
		if (kiemtraSach(p, sMaSach) == false)
		{
			cout << "Ma Sach Khong Co Trong Kho Hoac Dang Duoc Muon!\n";
			system("pause");
		}
		else
		{
			break;
		}
	}
	PhieuMuon PM(sMaSach, sMaBD);
	M.push_back(PM);
	cout << "Tao Phieu Muon Thanh Cong!\n";
	//ghi file: (ghi chen)
	ofstream fcout;
	fcout.open("PhieuMuon.txt", ios::app);
	//dung lenh "rbegin" de trinh vong lap nguoc, truy xuat den file BanDoc.txt va Sach.txt de ghi MaBD va MaSach
	fcout << M.rbegin()->getMaPM() << ";" << M.rbegin()->getBanDoc().getMaBD() << ";" << M.rbegin()->getSach().getsMasach() << ";" << M.rbegin()->getNgayMuon().getNgay()
		<< ";" << M.rbegin()->getNgayMuon().getThang() << ";" << M.rbegin()->getNgayMuon().getNam() << ";" << M.rbegin()->getNgayTra().getNgay()
		<< ";" << M.rbegin()->getNgayTra().getThang() << ";" << M.rbegin()->getNgayTra().getNam() << ";" << M.rbegin()->getTinhTrang();
	fcout.close();
	//xu ly tinh trang cua phieu muon:
	int nTinhTrangPM = M.rbegin()->getMaPM();
	//cap nhat tinh trang sach :
	for(int i = 0 ; i < p.size() ; i++)
	{
		if (p[i].getsMasach() == sMaSach)
		{
			p[i].setnTinhTrang(nTinhTrangPM); // cap nhat trinh trang sach tu phieu muon
			break;
		}
	}
	ghiDSSach(p);
}
void ghiDSPhieuMuon(vector <PhieuMuon> &M, vector <BanDoc*> b, vector <Sach> &p)
{
	ofstream fcout;
	fcout.open("PhieuMuon.txt");
	if (fcout.is_open() == true)
		cout << "Ghi file thanh cong!\n";
	else
		cout << "Ghi file that bai!\n";

	for (int i = 0; i < M.size(); i++)
	{
		M[i].writePM(fcout);
	}
	fcout.close();
}
void xuatDSPhieuMuon(vector <PhieuMuon> M)
{
	for (int i = 0; i < M.size(); i++)
	{
		M[i].outputPM();
	}
}
void docDSPhieuMuon(vector <PhieuMuon> &M)
{
	ifstream fcin;
	fcin.open("PhieuMuon.txt",ios::app);
	if (fcin.is_open() == true)
		cout << "Doc file thanh cong!\n";
	else
		cout << "Doc file that bai!\n";
	while (fcin.eof() == false)
	{
		PhieuMuon PM;
		PM.readPM(fcin);
		M.push_back(PM);
	}
	fcin.close();
}
//   BAN DOC:
bool kiemtraBanDoc(vector <BanDoc*> b, string sMaBD)
{
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->getMaBD() == sMaBD)
			return true;
	}
	return false;
}
void themBanDoc(vector <BanDoc*> &b)
{
	int nLoaiBD = 0;
	string sMaBD = " ", sHoten = " ", sKhoa = " ", sDiachi = " ", sSDT = " ";
	int nKhoaHoc = 0, nNgay = 0, nThang = 0, nNam = 0;
	//ham lay thoi gian hien tai:
	time_t rawtime;
	struct tm *info;
	//char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	nNgay = (info->tm_mday);
	nThang = (info->tm_mon + 1);
	nNam = (info->tm_year + 1900);
	while (true)
	{
		system("cls");
		MenuThemBanDoc();
		cout << "Chon loai Ban Doc: "; cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			int nSoLuong = nDemSLBanDocGV(b);
			std::string chuyenchuoi = std::to_string(nSoLuong + 1); //chuyen tu kieu int ve kieu chuoi, su du ham to_string
			sMaBD = "GV" + chuyenchuoi; // gan theo thu tu ban doc giao vien
			cout << "Nhap Ho va ten: ";
			rewind(stdin); getline(cin, sHoten);
			cout << "Nhap Khoa: "; 
			rewind(stdin); getline(cin, sKhoa);
			cout << "Nhap dia chi: ";
			rewind(stdin); getline(cin, sDiachi);
			cout << "Nhap SDT: ";
			rewind(stdin); getline(cin, sSDT);
			BanDoc * GV = new GiaoVien(1, sMaBD, sHoten, sKhoa, nNgay, nThang, nNam, sDiachi, sSDT);
			b.push_back(GV);
			//ghi file: (ghi chen)
			ofstream fcout;
			fcout.open("BanDoc.txt", ios::app);
			fcout << endl;
			fcout << nLoaiBD << ";" << sMaBD << "," << sHoten << ";" << sKhoa << ";" << nNgay << ";" << nThang << ";" << nNam << ";" << sDiachi << ";" << sSDT;
			fcout.close();
			cout << "Them Ban Doc Thanh Cong!\n";
			break;
		}
		if (nLoaiBD == 2)
		{
			int nSoLuong = nDemSLBanDocSV(b);
			std::string chuyenchuoi = std::to_string(nSoLuong + 1); //chuyen tu kieu int ve kieu chuoi, su du ham to_string
			sMaBD = "SV" + chuyenchuoi; // ma sv se tu dong tang dan , khong can phai nhap ma
			cout << "Nhap Ho va ten: ";
			rewind(stdin); getline(cin, sHoten);
			cout << "Nhap Khoa: ";
			rewind(stdin); getline(cin, sKhoa);
			cout << "Nhap Khoa Hoc: "; cin >> nKhoaHoc;
			BanDoc * SV = new SinhVien(2, sMaBD, sHoten, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			b.push_back(SV);
			//ghi file:(ghi chen)
			ofstream fcout;
			fcout.open("BanDoc.txt", ios::app);
			fcout << endl;
			fcout << nLoaiBD << ";" << sMaBD << ";" << sHoten << ";" << sKhoa << ";" << nNgay << ";" << nThang << ";" << nNam << ";" << nKhoaHoc;
			fcout.close();
			cout << "Them Ban Doc Thanh Cong!\n";
			break;
		}
		else if (nLoaiBD == 3)
		{
			break;
		}
		else
		{
			cout << "Nhap sai vui long nhap lai!\n";
		}
	}
}
void timkiemBanDoc(vector <BanDoc*> b, string sMaBD)
{
	int flag = 0;
	cout << "Nhap Ma Ban Doc can tim: ";
	rewind(stdin); getline(cin, sMaBD);
	for (int i = 0; i < b.size(); i++)
	{
		if (sMaBD == b[i]->getMaBD())
		{
			flag = 1;
			b[i]->outputBanDoc();
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "Ma Ban Doc Khong Ton Tai!\n";
	}
}
int nDemSLBanDocSV(vector <BanDoc*> b)
{
	int nLoaiBD = 0, nDem = 0;
	string sMaBD = " ", sHoten = " ", sKhoa = " ", sDiachi = " ", sSDT = " ";
	int nKhoaHoc = 0, nNgay = 0, nThang = 0, nNam = 0;
	ifstream fcin;
	fcin.open("BanDoc.txt");
	if (fcin.is_open() == true)
		cout << "Doc file thanh cong!\n";
	else
		cout << "Doc file that bai!\n";
	while (fcin.eof() == false)
	{
		fcin >> nLoaiBD;
		fcin.ignore(1);
		if (nLoaiBD == 1)
		{
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			rewind(stdin); getline(fcin, sDiachi, ';');
			rewind(stdin); getline(fcin, sSDT, '\n');
		}
		if (nLoaiBD == 2)
		{
			nDem++;
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			fcin >> nKhoaHoc; fcin.ignore(1, '\n');
		}
	}
	fcin.close();
	return nDem;
}
int nDemSLBanDocGV(vector <BanDoc*> b)
{
	int nLoaiBD = 0, nDem = 0;
	string sMaBD = " ", sHoten = " ", sKhoa = " ", sDiachi = " ", sSDT = " ";
	int nKhoaHoc = 0, nNgay = 0, nThang = 0, nNam = 0;
	ifstream fcin;
	fcin.open("BanDoc.txt");
	if (fcin.is_open() == true)
		cout << "Doc file thanh cong!\n";
	else
		cout << "Doc file that bai!\n";
	while (fcin.eof() == false)
	{
		fcin >> nLoaiBD;
		fcin.ignore(1);
		if (nLoaiBD == 1)
		{
			nDem++;
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			rewind(stdin); getline(fcin, sDiachi, ';');
			rewind(stdin); getline(fcin, sSDT, '\n');
		}
		if (nLoaiBD == 2)
		{
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			fcin >> nKhoaHoc; fcin.ignore(1, '\n');
		}
	}
	fcin.close();
	return nDem;
}
void ghiDSBanDoc(vector <BanDoc*> &b)
{
	int nLoaiBD = 0, nN = 0;
	ofstream fcout;
	fcout.open("BanDoc.txt");
	if (fcout.is_open() == true)
		cout << "Ghi file thanh cong!\n";
	else
		cout << "Ghi file that bai!\n";
	for (int i = 0; i < b.size(); i++)
	{
		b[i]->writeBanDoc(fcout);
	}
	fcout.close();
}
void xuatDSBanDoc(vector <BanDoc*> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		b[i]->outputBanDoc();
	}
}
void docDSBanDoc(vector <BanDoc*> &b)
{
	int nLoaiBD = 0, nN = 0;
	string sMaBD = " ", sHoten = " ", sKhoa = " ", sDiachi = " ", sSDT = " ";
	int nKhoaHoc = 0, nNgay = 0, nThang = 0, nNam = 0;
	ifstream fcin;
	fcin.open("BanDoc.txt");
	if (fcin.is_open() == true)
		cout << "Doc file thanh cong!\n";
	else
		cout << "Doc file that bai!\n";
	while(fcin.eof() == false)
	{
		fcin >> nLoaiBD;
		fcin.ignore(1);
		if (nLoaiBD == 1)
		{
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			rewind(stdin); getline(fcin, sDiachi, ';');
			rewind(stdin); getline(fcin, sSDT, '\n');
			BanDoc * GV = new GiaoVien(nLoaiBD,sMaBD, sHoten, sKhoa, nNgay, nThang, nNam, sDiachi,sSDT);
			b.push_back(GV);
		}
		if (nLoaiBD == 2)
		{
			rewind(stdin); getline(fcin, sMaBD, ';');
			rewind(stdin); getline(fcin, sHoten, ';');
			rewind(stdin); getline(fcin, sKhoa, ';');
			fcin >> nNgay; fcin.ignore(1);
			fcin >> nThang; fcin.ignore(1);
			fcin >> nNam; fcin.ignore(1);
			fcin >> nKhoaHoc; fcin.ignore(1, '\n');
			BanDoc * SV = new SinhVien(nLoaiBD, sMaBD, sHoten, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			b.push_back(SV);
		}
	}
	fcin.close();
}
//   SACH:
bool kiemtraSach(vector <Sach> p, string sMaSach)
{
	for (int i = 0; p.size(); i++)
	{
		if (p[i].getsMasach() == sMaSach)
			return true;
	}
	return false;
}
void timkiemSach(vector <Sach> p, string sMaSach)
{
	int flag = 0;
	cout << "Nhap ma sach can tim: ";
	rewind(stdin); getline(cin, sMaSach);
	for (int i = 0; i < p.size(); i++)
	{
		if (sMaSach == p[i].getsMasach())
		{
			flag = 1;
			p[i].output();
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "Ma Sach Khong Ton Tai!\n";
	}
}
int nDemSachConLai(vector <Sach> p)
{
	int nDem = 0;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].getnTinhTrang() == 0)
		{
			nDem++;
		}
	}
	return nDem;
}
int nDemSachDangMuon(vector <Sach> p)
{
	int nDem = 0;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].getnTinhTrang() != 0)
		{
			nDem++;
		}
	}
	return nDem;
}
void themSach(vector <Sach> &p )
{
	Sach xS;
	string sMaSach = " ", sTieuDe = " ", sTacGia = " ", sNXB = " ";
	float fGia = 0.0;
	int nNamPH = 0, nSoTrang = 0, nTinhTrang = 0;
	SS:
	cout << "Nhap Vao Ma Sach Can Them: ";
	rewind(stdin); getline(cin, sMaSach);
	if (xS.getsMasach() == sMaSach)
	{
		cout << "Ma Sach Da Ton Tai, Vui Long Nhap Lai!\n";
		goto SS;
	}
	cout << "Nhap vao tua de: ";
	rewind(stdin); getline(cin, sTieuDe);
	cout << "Nhap vao Tac Gia: ";
	rewind(stdin); getline(cin, sTacGia);
	cout << "Nhap vao NXB: ";
	rewind(stdin); getline(cin, sNXB);
	cout << "Nhap vao gia sach: "; cin >> fGia;
	cout << "Nhap vao nam phat hanh: "; cin >> nNamPH;
	cout << "Nhap vao so trang: "; cin >> nSoTrang;
	Sach S(sMaSach, sTieuDe, sTacGia, sNXB, fGia, nNamPH, nSoTrang,xS.getNgayNhapKho().getNgay() , xS.getNgayNhapKho().getThang(), xS.getNgayNhapKho().getNam(),0);
	p.push_back(S);
	cout << "Them Sach Thanh Cong!\n";
}
void xoaSach(vector <Sach> &p, string sMaSach)
{

	int flag = 0;
	SS:
	cout << "Nhap Vao Ma Sach Can Xoa: ";
	rewind(stdin); getline(cin, sMaSach);
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].getsMasach() == sMaSach && p[i].getnTinhTrang() == 0)
		{
			flag = 1;
			cout << "Xoa Sach Thanh Cong!\n";
			p.erase(p.begin() + i);
			break;
		}
	}
	if (flag == 0)
	{
		cout << "Ma Sach Khong Ton Tai Hoac Dang Duoc Muon\n";
		goto SS;
	}
}
void ghiDSSach(vector <Sach> &p)
{
	ofstream fcout;
	fcout.open("Sach.txt");
	if (fcout.is_open() == true)
		cout << "Ghi file thanh cong!\n";
	else
		cout << "Ghi file that bai!\n";

	for (int i = 0; i < p.size(); i++)
	{
		p[i].writeSach(fcout);
	}
	fcout.close();
}
void xuatDSSach(vector <Sach> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		p[i].output();
	}
}
void docDSSach(vector <Sach> &p)
{
	string sMaSach = " ", sTieuDe = " ", sTacGia = " ", sNXB = " ";
	float fGia = 0.0;
	int nNamPhatHanh = 0, nSoTrang = 0, nTinhTrang = 0;
	int nNgay = 0, nThang = 0, nNam = 0;
	ifstream fcin;
	fcin.open("Sach.txt", ios::app);
	while (fcin.eof() == false)
	{
		getline(fcin, sMaSach, ';');
		getline(fcin, sTieuDe, ';');
		getline(fcin, sTacGia, ';');
		getline(fcin, sNXB, ';');
		fcin >> fGia; fcin.ignore(1);
		fcin >> nNamPhatHanh; fcin.ignore(1);
		fcin >> nSoTrang; fcin.ignore(1);
		fcin >> nNgay; fcin.ignore(1);
		fcin >> nThang; fcin.ignore(1);
		fcin >> nNam; fcin.ignore(1);
		fcin >> nTinhTrang; fcin.ignore(1);
		Sach S(sMaSach, sTieuDe, sTacGia, sNXB, fGia, nNamPhatHanh, nSoTrang, nNgay, nThang, nNam, nTinhTrang);
		p.push_back(S);
	}
	fcin.close();
}
//Cac Chuc Nang:
void CN_TimKiemTT()
{
	system("cls");
	MenuTimKiemTT();
	do
	{
		cout << "Vui Long Chon Thong Tin Can Tim Kiem: "; cin >> nLoaiTimKiem;
		switch (nLoaiTimKiem)
		{
		case 1:
		{
			timkiemSach(p, sMaSach);
			break;
		}
		case 2:
		{
			timkiemBanDoc(b, sMaBD);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			return;
			break;
		}
	} while (nLoaiTimKiem >= 1 || nLoaiTimKiem <=2);
}
void CN_QuanLySach()
{
	system("cls");
	MenuSach();
	do
	{
		cout << "Chon Chuc Nang Quan Ly Sach: "; cin >> nQuanLySach;
		switch (nQuanLySach)
		{
		case 1:
		{
			themSach(p);
			break;
		}
		case 2:
		{
			xoaSach(p, sMaSach);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			return;
			break;
		}
	} while (nQuanLySach >= 1 || nLoaiTimKiem <= 2);
}
void CN_QuanLyBanDoc()
{
	system("cls");
	MenuBanDoc();
	do
	{
		cout << "Vui Long Chon Chuc Nang Quan Ly Ban Doc: "; cin >> nQuanLyBanDoc;
		switch (nQuanLyBanDoc)
		{
		case 1: // them ban doc
		{
			themBanDoc(b);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			return;
			break;
		}
	} while (nQuanLyBanDoc >= 1 );
}
void CN_QuanLyPhieuMuon()
{
	system("cls");
	MenuPhieuMuon();
	do
	{
		cout << "Vui Long Chon Chuc Nang Quan Ly PM: "; cin >> nQuanLyPhieuMuon;
		switch (nQuanLyPhieuMuon)
		{
		case 1: // tao phieu muon
		{
			taoPhieuMuon(M, b, p);
			break;
		}
		case 2: // tra sach
		{
			traSach(M, b, p);
			break;
		}
		case 3: //xem thong tin phieu muon
		{
			xuatDSPhieuMuon(M);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			return;
			break;
		}
	} while (nQuanLyPhieuMuon >= 1 || nQuanLyPhieuMuon <= 3);
}
void CN_ThongKe()
{
	system("cls");
	MenuThongKe();
	do
	{
		cout << "Vui Long Chon Chuc Nang Thong Ke: "; cin >> nThongKe;
		switch (nThongKe)
		{
		case 1: // thong ke so sach dang duoc muon
		{
			cout << "Tong So Sach Dang Duoc Muon La: " << nDemSachDangMuon(p) << endl;
			break;
		}
		case 2: // thong ke so sach con lai trong kho
		{
			cout << "Tong So Sach Con Lai Trong Kho La: " << nDemSachConLai(p) << endl;
			break;
		}
		case 3: // liet ke so sach ma 1 ban doc dang muon:
		{
			lietKeSachMaBanDocDangMuon(M, p);
			break;
		}
		default:
			Color(13);
			cout << "Ban Chon thoat chuong trinh!\n";
			return;
			break;
		}
	} while (nThongKe >= 1 || nThongKe <= 3);
}
////Tao cac Menu:
void MenuThongKe()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tTHONG KE\t\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Tong So Sach Duoc Muon.\n";
	cout << "\t\t\t\t2.Tong So Luong Sach Con Lai.\n";
	cout << "\t\t\t\t3.Liet Ke Sach 1 Ban Doc Dang Muon.\n";
	cout << "\t\t\t\t4.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuSach()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY SACH\t\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Them Sach.\n";
	cout << "\t\t\t\t2.Xoa Sach.\n";
	cout << "\t\t\t\t3.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuThemBanDoc()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tTHEM BAN DOC\t\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Them Ban Doc Giao Vien.\n";
	cout << "\t\t\t\t2.Them Ban Doc Sinh Vien.\n";
	cout << "\t\t\t\t3.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuBanDoc()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY BAN DOC\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Them Ban Doc.\n";
	cout << "\t\t\t\t2.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuPhieuMuon()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY PHIEU MUON\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Tao Phieu Muon.\n";
	cout << "\t\t\t\t2.Tra Sach.\n";
	cout << "\t\t\t\t3.Xem Thong Tin Phieu Muon.\n";
	cout << "\t\t\t\t4.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuTimKiemTT()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tTIM KIEM THONG TIN\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Tim Kiem Thong Tin Sach.\n";
	cout << "\t\t\t\t2.Tim Kiem Thong Tin Ban Doc.\n";
	cout << "\t\t\t\t3.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuQuanLy()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tCHUC NANG QUAN LY\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Quan Ly Phieu Muon.\n";
	cout << "\t\t\t\t2.Quan Ly Sach\n";
	cout << "\t\t\t\t3.Quan Ly Ban Doc.\n";
	cout << "\t\t\t\t4.Thong Ke.\n";
	cout << "\t\t\t\t5.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuChinh()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY THU VIEN\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Hien Thi Thong Tin Sach.\n";
	cout << "\t\t\t\t2.Hien Thi Thong Tin Ban Doc.\n";
	cout << "\t\t\t\t3.Tim Kiem Thong Tin.\n";
	cout << "\t\t\t\t4.Quan Ly.\n";
	cout << "\t\t\t\t5.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
string passwordInput(unsigned maxLength)
{
	string password = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!password.empty()) password.erase(password.size() - 1);
		}
		else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && password.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			password += c;
		}
	}
	return password;
}
void Color(int nX)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, nX);
}