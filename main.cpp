//thu vien:
#include "Admin.h"
#include "BanDoc.h"
#include "Sach.h"
#include "PhieuMuon.h"
#include "Date.h"
#include <vector>
//khai bao bien toan cuc:

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
void MenuSach();
void MenuThongKe();
//Ban Doc:
void docDSBanDoc(vector <BanDoc*> &p);
void ghiDSBanDoc(vector <BanDoc*> p);
void xuatDSBanDoc(vector <BanDoc*> p);
void timBanDoc(vector <BanDoc*> p, string sMaBD);
//void themDSBanDoc(vector <BanDoc*> &p);
//Sach:
void docDSSach(vector <Sach> &s);
void ghiDSSach(vector <Sach> s);
void xuatDSSach(vector <Sach> s);
//khai bao bien toan cuc:
vector <Sach> s;

//chuong trinh chinh:
void main()
{
	int nChon = 0;
	docDSSach(s);
	string sMaBD = "";
	do
	{
		system("cls");
		MenuChinh();
		cout << "Chon Chuc Nang So: "; cin >> nChon;
		switch (nChon)
		{
		case 1:
		{
			xuatDSSach(s);
			break;
		}
		case 2:
		{
			ghiDSSach(s);
			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{
			int nQuanly = 0;
			system("cls");
			MenuQuanLy();
			cout << "Chon Chuc Nang So: "; cin >> nQuanly;
			do
			{
			
				switch (nQuanly)
				{
				case 1:
				{
					MenuPhieuMuon();
					break;
				}
				case 2:
				{
					MenuSach();
					break;
				}
				case 3:
				{
					MenuBanDoc();
					break;
				}
				case 4:
				{
					MenuThongKe();
					break;
				}
				default: cout << " Ban chon chuc nang thoat quan li!!";
					break;
				}

			} while (nQuanly < 1 || nQuanly > 4);
			system("pause");

			break;
		}
		default: cout << " Ban chon chuc nang thoat chuong trinh!!";
			break;
		}

	} while (nChon < 1 || nChon > 5);
	system("pause");
}
//dinh nghia nguyen mau ham con:
//Sach:
void xuatDSSach(vector <Sach> s)
{
	cout << "Danh sach co:";
	for (int i = 0; i < s.size(); i++)
	{
		 s[i].output();
	}
}
void ghiDSSach(vector <Sach> s)
{
	ofstream fcout;
	fcout.open("Sach.txt");
	fcout << s.size() << endl;
	for (int i = 0; i < s.size(); i++)
	{
		s[i].writeSach(fcout);
	}
	fcout.close();
}
void docDSSach(vector <Sach> &s)
{
	int nN = 0;
	ifstream fcin;
	fcin.open("Sach.txt");
	if (fcin.is_open() == true)
	{
		cout << "Mo file thanh cong!\n";
	}
	else
	{
		cout << "Mo file that bai!\n";
	}
	Sach S;
	fcin >> nN; fcin.ignore(1);
	for (int i = 0; i <nN; i++)
	{
		S.readSach(fcin);
		s.push_back(S);
	}
	fcin.close();
}

//Ban Doc:
void timBanDoc(vector <BanDoc*> p, string sMaBD)
{
	cout << "Nhap ma ban doc can tim: ";
	rewind(stdin);
	getline(cin, sMaBD);
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i]->getMaBD() == sMaBD)
		{
			p[i]->outputBanDoc();
		}
	}
}
void xuatDSBanDoc(vector <BanDoc*> p)
{
	for (int i = 0; i < p.size(); i++)
	{
		p[i]->outputBanDoc();
	}
}
void ghiDSBanDoc(vector <BanDoc*> p)
{
	ofstream fcout;
	fcout.open("BanDoc.txt");
	for (int i = 0; i < p.size(); i++)
	{
		p[i]->writeBanDoc(fcout);
	}
	fcout.close();
}
void docDSBanDoc(vector <BanDoc*> &p)
{
	ifstream fcin;
	fcin.open("BanDoc.txt");
	for(int i = 0 ; i < p.size(); i++)
	{
		p[i]->readBanDoc(fcin);
	}
	fcin.close();
}
//Tao cac Menu:
void MenuThongKe()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tTHONG KE\t"; Color(10); cout << "*\n";
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
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY SACH\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Them Sach.\n";
	cout << "\t\t\t\t2.Xoa Sach.\n";
	cout << "\t\t\t\t3.Thoat.\n";
	cout << "\t\t\t\t****************************************\n";
}
void MenuBanDoc()
{
	Color(10); cout << "\n\t\t\t\t\t*********************************\n";
	Color(10); cout << "\t\t\t\t\t* ";  Color(14); cout << "\tQUAN LY BAN DOC\t"; Color(10); cout << "*\n";
	Color(10); cout << "\t\t\t\t\t*********************************\n";
	cout << "\t\t\t\t1.Them Ban Doc.\n";
	cout << "\t\t\t\t2.Danh Sach Ban Doc Dang Muon Sach.\n";
	cout << "\t\t\t\t3.Thoat.\n";
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