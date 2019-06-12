
void xuatmenu()
{
	cout << "\n=============== HE THONG QUAN LY HANG HOA =====================";
	cout << "\n0: Thoat chuong trinh.";
	cout << "\n1: Tao danh sach mat hang.";
    cout << "\n2: Xuat cac mat hang theo thu tu ABC ten mat hang.";
	cout << "\n3: Tinh tong cac gia tri mat hang.";
	cout << "\n4: Cho biet cac gia tri lon nhat trong cua hang.";
	cout << "\n5: Xuat cac mat hang het hang su dung. ";
	cout << "\n6: Sap xep xuat cac mat hang theo tang loai. ";
	cout << "\n7: Tim nhung mat hang con su dung khong qua 30 ngay.";
	//cout << "\n8: Liet ke nhung mat hang da ban het. ";
	cout << "\n8 Xoa san pham.";
	cout << "\n9: Tinh so luong mat hang banh va keo.";
	cout << "\n10:Tim mat hang bia co gia re nhat.";


}
int chonmenu(int somenu)
{
	
	int stt;
	for (; ;)
	{
		system("CLS");
		xuatmenu();
		cout << "\n\n\n(Chon chuc nang 1 de tao danh sach,truoc khi chon chuc nang khac)";
		cout << "\n\nChon so trong khoang(0,.." << somenu << ") stt:= ";
		cin >> stt;
		
		if (0 <= stt&&stt <= somenu)
			break;
	}

	return stt;
}

void xulymenu(int menu,Hanghoa sp[MAX],int &n)
{
	char mathang[3];
	int kq;
	char Tenmathang[MAX];
	int ngay, thang, nam;
	char *f = new char[MAX];
	
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0 Thoat chuong trinh.";
		break;
	case 1:
		system("CLS");
		cout << "\n1 Tao danh sach mat hang.";
		do
		{
			cout << "\nNhap ten tep tin:=";
				cin >> f;
				kq = Taodanhsach(f, sp, n);
				if (!kq)
				{
					cout << "\nMoi nhap lai ten......";
				}
		} while (!kq);
		cout << "\nTep tin da chuyen vao danh sach " << f;
	    xuatDSSP(sp, n);
		cout << "\nSo san pham trong danh sach := " << n;
		break;
	case 2:
		system("CLS");
		cout << "\n2 Xuat cac mat hang theo thu tu ABC ten mat hang.";
		cout << "\nDanh sach hien hanh";
		xuatDSSP(sp, n);
		sapxep_ten_theo_ABC(sp, n, Tenmathang);
		cout << "\nDanh sach sau khi sap xep";
		xuatDSSP(sp, n);
		break;
	case 3:
		system("CLS");
		cout << "\n3 Tinh tong cac gia tri mat hang.";
		kq = Tinh_Tong_Don_Gia(sp, n);
		cout << "\nTong gia tri mat hang: "<<kq<<" VND";

		break;
	case 4:
		system("CLS");
		cout << "\n4 Cho biet cac gia tri lon nhat trong cua hang.";
		cout << "\nMat hang co gia tri lon nhat trong cua hang: ";
	    Giatri_Max_mat_hang(sp, n);
		
		break;
	case 5:
		system("CLS");
		cout << "\n5 Xuat cac mat hang het hang su dung. ";
		cout << "\nNhap ngay:";
		cin >> ngay;
		cout << "\nNhap thang:";
		cin >> thang;
		cout << "\nNhap nam:";
		cin >> nam;
		system("CLS");
		xuatcacmathang_hethansudung(sp, n, ngay, thang, nam);

		break;
	case 6:
		system("CLS");
		cout << "\n6 Sap xep xuat cac mat hang theo tung loai. ";
		sapxep_xuat_theotungloai(sp, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7 Tim nhung mat hang con su dung khong qua 30 ngay.";
		cout << "\nNhap ngay:";
		cin >> ngay;
		cout << "\nNhap thang:";
		cin >> thang;
		cout << "\nNhap nam:";
		cin >> nam;
		system("CLS");
		tim_hang_khongqua30day(sp, n, ngay, thang, nam);
		break;
	case 8:
		system("CLS");
		cout << "\n8 Xoa san pham.";
		cout << "\nDanh sach hien hanh.";
		xuatDSSP(sp, n);
		cout << "\nNhap ten san pham can xoa:";
		_flushall();
		gets_s(Tenmathang, MAX);
		gets_s(Tenmathang, MAX);
		xoasp(sp, n, Tenmathang);
		cout << "\nDanh sach mat hang sau khi xoa ";
		xuatDSSP(sp, n);
		break;
	case 9:
		char loaimathang[MAX];
		system("CLS");
		cout << "\n9 Tinh so luong mat hang banh va keo.";
		kq = tinhsoluong_banh_keo(sp, n, loaimathang);
	    cout << "\nSo luong mat hang banh va keo:= "<<kq;
		break;
	case 10:
		system("CLS");
		cout << "\n10 Tim mat hang bia co gia re nhat.";
		cout << "\nBia co gia re nhat la:";
		tim_bia_re(sp, n, loaimathang);
		
		break;
	}
	_getch();

}