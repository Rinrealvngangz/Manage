void xuatmenu()
{
	cout << "\n0  Thoat khoi chuong trinh";
	cout << "\n1  Tao danh sach sinh vien";
	cout << "\n2  Xem danh sach sinh vien";
	cout << "\n3  Nhap nhan vien ";
	cout << "\n4  Xoa 1 nhan vien";
	cout << "\n5  Sua thong tin nhan vien";
	cout << "\n6  Tim nhan vien theo ma so";
	cout << "\n7  Tim nhan vien theo ma ten";
	cout << "\n8  Sap xep danh sach nhan vien tang dan theo ma nhan vien";
	cout << "\n9  Sap xep danh sach nhan vien tang dan theo ten va luong";
	cout << "\n10 Tinh tong luong thang";
	cout << "\n11 Liet ke cac nhan vien co thang luong>=x ";
	cout << "\n12 Liet ke cac nhan vien co nam sinh trong khoang[u,v]";
}

int Chonmenu(int somenu)
{
	int stt;
	for(; ;)
	{ 
		system("CLS");
	   xuatmenu();
	   cout << "\nNhap 1 so trong khoang [0..." << somenu << "] de chon chuc nang,stt =";
	   cin >> stt;
	   if (0 <= stt && stt  <= somenu)
		   break;
	}
	return stt;


}

void xulymenu(int menu,NhanVien nv[MAX],int &n)
{
	unsigned int  v;
	unsigned int u;
	double x;
	char Hoten[MAX];
	int maNV;
	char *f=new char[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0Thoat khoi chuong trinh";
		cout << "\nNhan phim bat ky thoat chuong trinh";
		break;
	case 1:
		
		system("CLS");
		cout << "\n1 Tao danh sach sinh vien";
		do
		{
			cout << "\nNhap ten tap tin :=";
			cin >> f;
			kq=Chuyen_TT_DSNV(f, nv, n);
			if (!kq)
			{
				cout << "\nXin nhap lai ten ";
			}
		} while (!kq);

			cout << "Da chuyen thanh cong tap tin " << f << " vao danh sach";
		xuatDSNV(nv, n);
		
		break;
	case 2:
		system("CLS");
		cout << "\n2 Xem danh sach sinh vien";
		xuatDSNV(nv, n);
		cout << "\nSo luong nhan vien trong danh sach = " << n;
		break;
	case 3:
		
		system("CLS");
		cout << "\n3 Nhap nhan vien ";
		nhapDSSV(nv, n);
		system("CLS");
		cout << "\nDanh sach ket qua :";
		xuatDSNV(nv, n);
		cout << "\nSo luong sinh vien trong danh sach:"<<n;
		
		break;
	case 4:
		system("CLS");
		cout << "\n4 Xoa 1 nhan vien(MANV)";
		cout << "\nNhap ma nhan vien can xoa:";
		cin >> maNV;
		cout << "\nDanh sach hien hanh:";
		xuatDSNV(nv, n);
		xoaNV(nv, n, maNV);
		cout << "\n\n\nDanh sach nhan vien sau khi xoa:";
		xuatDSNV(nv, n);
		cout << "\So luong nhan vien trong danh sach:=" << n;
		break;
	case 5:
		system("CLS");
		cout << "\n5 Sua thong tin nhan vien";
		cout << "\nNhap ma nhan vien can sua:";
		cin >> maNV;
		cout << "\nDanh sach hien hanh:";
		xuatDSNV(nv, n);
		system("CLS");
		suathongtin_MNV(nv, n, maNV);
		system("CLS");
		cout << "\n\n\nDanh sach nhan vien sau khi sua:";
		xuatDSNV(nv, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6 Tim nhan vien theo ma so";
		cout << "\nNhap ma nhan vien can tim:";
		cin >> maNV;
		tim_NV_theo_MS(nv, n, maNV);
		break;
	case 7:
		system("CLS");
		cout << "\n7 Tim nhan vien theo ten";
		cout << "\nNhap ten nhan vien:";
		gets_s(Hoten, MAX);
		_flushall();
		gets_s(Hoten, MAX);
		tim_NV_theo_ten(nv, n, Hoten);
		break;
	case 8:
		system("CLS");
		cout << "\n8 Sap xep danh sach nhan vien tang dan theo ma nhan vien";
		cout << "\n\n\nDanh sach hien hanh";
		xuatDSNV(nv, n);
		Sapxep_NV_MS(nv, n);
		cout << "\n\n\nDanh sach sau khi sap xep";
		xuatDSNV(nv, n);
		break;
	case 9:
		system("CLS");
		cout << "\n9 Sap xep danh sach nhan vien tang dan theo ten va luong";
		cout << "\n\n\nDanh sach hien hanh";
		xuatDSNV(nv, n);
		Sapxep_NV_hoten_luong(nv, n);
		cout << "\n\n\nDanh sach sau khi sap xep";
		xuatDSNV(nv, n);
		break;
	case 10:
		system("CLS");
		cout << "\n10 Tinh tong luong thang";
		kq = tinhtong_luong(nv, n);
		cout << "\nTong Luong thang nhan vien:" << kq;
		break;
	case 11:
	
		system("CLS");
		cout << "\n11 Liet ke cac nhan vien co thang luong>=x ";
		cout << "\nNhap so tien : x =";
		cin >> x;
		lietke_NV_lonhon_x(nv, n, x);
		cout << "\nDanh sach nhan vien co tien lon hon " << x;
		
		break;
	case 12:
		system("CLS");
		cout << "\n12 Liet ke cac nhan vien co nam sinh trong khoang[u,v]";
		cout << "\nNhap nam sinh u:";
		cin >> u;
		cout << "\nNhap nam sinh v:";
		cin >> v;
		lietke_NS_NV(nv, n, v, u);
		break;
	}
	_getch();
}