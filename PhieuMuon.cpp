#include "PhieuMuon.h"
//phuong thuc lay gia tri:
BanDoc PhieuMuon::getBanDoc()
{
	return this->xBandoc.getMaBD();
}
Sach PhieuMuon::getSach()
{
	return this->xSach.getsMasach();
}
Date PhieuMuon::getNgayMuon()
{
	return this->xNgaymuon;
}
Date PhieuMuon::getNgayTra()
{
	return this->xNgaytra;
}
int PhieuMuon::getMaPM()
{
	return  this->nMaPM;
}
int PhieuMuon::getTinhTrang()
{
	return this->nTinhTrang;
}
//phuong thuc cap nhat gia tri:
void PhieuMuon::setBanDocPM(BanDoc xBD)
{
	this->xBandoc = xBD;
}
void PhieuMuon::setSachPM(Sach xS)
{
	this->xSach = xS;
}
void PhieuMuon::setTinhTrang(int nTinhTrang)
{
	this->nTinhTrang = nTinhTrang;
}
//ham xuat , doc , ghi:
void PhieuMuon::outputPM()
{
	cout << "*******THONG TIN PHIEU MUON*******************\n";
	cout << "Ma phieu muon: "  << this->getMaPM() << endl;
	cout << "Ma Ban doc : " << this->getBanDoc().getMaBD() << endl;
	cout << "Ma Sach: " << this->getSach().getsMasach() << endl;
	cout << "Ngay muon: " ; this->xNgaymuon.print();
	cout << "Ngay tra: " ; this->xNgaytra.print();
	cout << "Tinh trang: " << this->getTinhTrang()	 << endl;
}
void PhieuMuon::readPM(ifstream &fcin)
{
	fcin >> this->nMaPM;
	fcin.ignore(1);
	rewind(stdin);
	getline(fcin, this->xBandoc.sMaBD, ';');
	rewind(stdin);
	getline(fcin, this->xSach.sMasach, ';');
	fcin >> this->xNgaymuon.nNgay;	fcin.ignore(1);
	fcin >> this->xNgaymuon.nThang;	fcin.ignore(1);
	fcin >> this->xNgaymuon.nNam;	fcin.ignore(1);
	fcin >> this->xNgaytra.nNgay;	fcin.ignore(1);
	fcin >> this->xNgaytra.nThang;	fcin.ignore(1);
	fcin >> this->xNgaytra.nNam;	fcin.ignore(1);
	fcin >> this->nTinhTrang;
}
void PhieuMuon::writePM(ofstream &fcout)
{
	fcout << this->nMaPM << ";";
	fcout << this->xBandoc.sMaBD << ";";
	fcout << this->xSach.sMasach << ";";
	fcout << this->xNgaymuon.nNgay << ";";
	fcout << this->xNgaymuon.nThang << ";";
	fcout << this->xNgaymuon.nNam << ";";
	fcout << this->xNgaytra.nNgay << ";";
	fcout << this->xNgaytra.nThang << ";";
	fcout << this->xNgaytra.nNam << ";";
	fcout << this->nTinhTrang << endl;
}
//ham tinh ngay tra sach:
Date &PhieuMuon::tinhNgayTra()
{
	switch (xNgaymuon.nThang)
	{
		//nhung thang co 31 ngay
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		xNgaytra.nNgay = xNgaymuon.nNgay + 7;
		if (xNgaytra.nNgay > 31)
		{
			xNgaytra.nNgay = xNgaytra.nNgay - 31;
			xNgaytra.nThang++;
		}
		if (xNgaytra.nThang > 12) // cho thang 12
		{
			xNgaytra.nThang = 1;
			xNgaytra.nNam++;
		}
		break;
	}
	//nhung thang co 30 ngay:
	case 4: case 6: case 9: case 11: 
	{
		xNgaytra.nNgay = xNgaymuon.nNgay + 7;
		if (xNgaytra.nNgay > 30)
		{
			xNgaytra.nNgay = xNgaytra.nNgay - 30;
			xNgaytra.nThang++;
		}
		break;
	}
	default:
	{
		if ((xNgaymuon.nNam % 400 == 0) || ((xNgaymuon.nNam % 4 == 0) && xNgaymuon.nNam % 100 != 0))
		{
			xNgaytra.nNgay = xNgaymuon.nNgay + 7;
			if (xNgaytra.nNgay > 29)
			{
				xNgaytra.nNgay = xNgaytra.nNgay - 29;
				xNgaytra.nThang++;
			}
		}
		else // nam khong nhuan co 28 ngay o thang 2 
		{
			xNgaytra.nNgay = xNgaymuon.nNgay + 7;
			if (xNgaytra.nNgay > 28)
			{
				xNgaytra.nNgay = xNgaytra.nNgay - 28;
				xNgaytra.nThang++;
			}
		}
		break;
	}
	}
	return xNgaytra;
}