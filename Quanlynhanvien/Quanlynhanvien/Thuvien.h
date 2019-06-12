#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

typedef unsigned short int  Byte;

struct ngaythangnam
{
	Byte ngaysinh;
	Byte thangsinh;
	unsigned int namsinh;

};

struct NhanVien
{
	int maNV;
	char Hoten[MAX];
	ngaythangnam ntns;
	char queQuan[MAX];
	double Luong;
};



int Chuyen_TT_DSNV(char *filename, NhanVien nv[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "Loi mo file!";
		
		return 0;
	}
	int maNV;
	char Hoten[MAX];
	char queQuan[MAX];
	double Luong;
	int ngaysinh, thangsinh, namsinh;

	n = 0;

	in >> maNV; nv[n].maNV = maNV;
	in >> Hoten; strcpy_s(nv[n].Hoten, Hoten);
	in >> ngaysinh; nv[n].ntns.ngaysinh = ngaysinh;
	in >> thangsinh; nv[n].ntns.thangsinh = thangsinh;
	in >> namsinh; nv[n].ntns.namsinh = namsinh;
	in >> queQuan; strcpy_s(nv[n].queQuan, queQuan);
	in >> Luong; nv[n].Luong = Luong;

	while (!in.eof())
	{
		n++;
		in >> maNV; nv[n].maNV = maNV;
		in >> Hoten; strcpy_s(nv[n].Hoten, Hoten);
		in >> ngaysinh; nv[n].ntns.ngaysinh = ngaysinh;
		in >> thangsinh; nv[n].ntns.thangsinh = thangsinh;
		in >> namsinh; nv[n].ntns.namsinh = namsinh;
		in >> queQuan; strcpy_s(nv[n].queQuan, queQuan);
		in >> Luong; nv[n].Luong = Luong;

	}
	//n++;
	in.close();
	
}

void xuattieudengangdoi()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	for (i = 0; i <= 76; i++)
		cout << NGANGDOI;
	cout << ':';

}
void xuattieudengangdon()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	for (i = 0; i <= 76; i++)
		cout << NGANGDON;
	cout << ':';

}

void xuattieude()
{
	xuattieudengangdoi();
	cout << "\n";
	cout << setiosflags(ios::left)
	  << ':'
	 << setw(10) << "Ma NV"
	 << setw(20) << "Hoten"
	 << setw(8) << "Ngay"
	 << setw(8) << "Thang"
	 << setw(8) << "Nam"
	 << setw(18) << "Quequan"
     << setw(5) << "Luong"
	 << ':';
	xuattieudengangdoi();
}

void xuat1NV(NhanVien &nv)
{
	cout << "\n";
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << nv.maNV
		<< setw(22) <<nv.Hoten
		<< setw(3) <<nv.ntns.ngaysinh<<" / "
		<< setw(5) <<nv.ntns.thangsinh<<" / "
		<< setw(8) <<nv.ntns.namsinh
		<< setw(12) <<nv.queQuan
		<< setw(6) <<setiosflags(ios::fixed)<<setprecision(2)<< nv.Luong
		<< ':';
	cout << endl;

}

void xuatDSNV(NhanVien nv[MAX], int n)
{
	int i;
	xuattieude();
	for (i = 0; i < n; i++)
	{
		xuat1NV(nv[i]);
		if ((i + 1) % 5 == 0)

			xuattieudengangdon();

		xuattieudengangdoi;
	}
}

void nhap1nv(NhanVien &p)
{

	cout << "\nNhap Ma nhan vien:";
	_flushall();
	cin >> p.maNV;

	cout << "\nNhap Ho va Ten:";
	_flushall();
	gets_s(p.Hoten, MAX);
	cout << "\nNhap ngay sinh:";
	_flushall();
	cin >> p.ntns.ngaysinh;
	cout << "\nNhap thang sinh:";
	_flushall();
	cin >> p.ntns.thangsinh;
	cout << "\nNhap nam sinh:";
	_flushall();
	cin >> p.ntns.namsinh;
	gets_s(p.Hoten, MAX);
	cout << "\nNhap Que quan:";
	gets_s(p.queQuan, MAX);
	cout << "\nNhap Luong :";
	_flushall();
	cin >> p.Luong;
}

void nhapDSSV(NhanVien nv[MAX], int &n)
{
	int i;
	cout << "\nNhap so luong nhan vien:";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		system("CLS");
		cout << "\n So nhan vien thu " << i + 1;
		nhap1nv(nv[i]);
	}

}

void xoaNV(NhanVien nv[MAX], int &n, int maNV)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n + 1; j++)
			if ((nv[i]).maNV == maNV)
				nv[j - 1] = nv[j];
	n--;

}

void suathongtin_MNV(NhanVien nv[MAX], int &n, int maNV)
{
	char tl;
	int i;
	for (i = 0; i < n; i++)
		if (nv[i].maNV == maNV)
			break;
	cout << "\nSua thong tin nhan vien:";
		cout << "\nSua Ma nhan vien ,Neu khong nhan k:";
		tl = _getch();
		if (tl != 'k'&& tl != 'K')
		{
			cout << "\nNhap Ma nhan vien:";
			_flushall();
			cin >> nv[i].maNV;
			gets_s(nv[i].queQuan, MAX);
		}

		cout << "\nSua Ho va ten ,Neu khong nhan k:";
		tl = _getch();
		if (tl != 'k'&& tl != 'K')
		{
			cout << "\nNhap Ho va Ten:";
			_flushall();
			gets_s(nv[i].Hoten, MAX);
		}
		cout << "\nSua ngay, thang , nam ,Neu khong nhan k:";
		tl = _getch();
		if (tl != 'k'&& tl != 'K')
		{
			cout << "\nNhap ngay sinh:";
			_flushall();
			cin >> nv[i].ntns.ngaysinh;
			cout << "\nNhap thang sinh:";
			_flushall();
			cin >> nv[i].ntns.thangsinh;
			cout << "\nNhap nam sinh:";
			_flushall();
			cin >> nv[i].ntns.namsinh;
			gets_s(nv[i].queQuan, MAX);
		}
		cout << "\nSua Que Quan,Neu khong nhan k:";
		tl = _getch();
		if (tl != 'k'&& tl != 'K')
		{
			cout << "\nNhap Que quan:";
			gets_s(nv[i].queQuan, MAX);
		}
		cout << "\nSua Luong nhan vien ,Neu khong nhan k:";
		tl = _getch();
		if (tl != 'k'&& tl != 'K')
		{
			cout << "\nNhap Luong :";
			_flushall();
			cin >> nv[i].Luong;
		}

}

void hoanvi(NhanVien &p, NhanVien &q)
{
	NhanVien t;
	t = p;
	p = q;
	q = t;
}


void tim_NV_theo_MS(NhanVien nv[MAX], int &n, int maNV)
{
	
	int i;
	int dem = 0;
	for (i = 0; i < n; i++)
		if (nv[i].maNV == maNV)
			dem++;
      if (!dem)
	
			cout << "\nkhong co nhan vien co ma so " << maNV << " trong danh sach";
			
	else
	{
		cout << "\nCo " << dem << " nhan vien trong danh sach co ma so la: " << maNV;
		xuattieude();
		xuattieudengangdoi();
		for (i = 0; i < n; i++)
			if (nv[i].maNV == maNV)
			{
				xuat1NV(nv[i]);
			}
	}
}
void tim_NV_theo_ten(NhanVien nv[MAX], int &n, char Hoten[MAX])
{

	int i;
	int dem = 0;
	for (i = 0; i < n; i++)
		if (_strcmpi(nv[i].Hoten, Hoten) == 0)
			dem++;
	if (!dem)
	{
		cout << "\nkhong co nhan vien co ten " << Hoten << " trong danh sach";
	}

	else
	{
		cout << "\nCo " << dem << " nhan vien trong danh sach co ma so la: " << Hoten;
		xuattieude();
		xuattieudengangdoi();
		for (i = 0; i < n; i++)
			if (_strcmpi(nv[i].Hoten, Hoten)== 0)
			{
				xuat1NV(nv[i]);
			}
	}
}

void Sapxep_NV_MS(NhanVien nv[MAX], int &n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (nv[i].maNV > nv[j].maNV)
				hoanvi(nv[i],nv[j]);

}
void Sapxep_NV_hoten_luong(NhanVien nv[MAX], int &n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if(_strcmpi(nv[i].Hoten,nv[j].Hoten)>0)
				hoanvi(nv[i], nv[j]);

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			if (_strcmpi(nv[i].Hoten, nv[j].Hoten) == 0)
				if (nv[i].Luong > nv[j].Luong)
					hoanvi(nv[i], nv[j]);
	}

}

double tinhtong_luong(NhanVien nv[MAX], int &n)
{
	int i;
	double sum=0;
	for (i = 0; i < n; i++)
		sum += nv[i].Luong;

	return sum;
}
void lietke_NV_lonhon_x(NhanVien nv[MAX], int &n, double x)
{
	int i;
	xuattieude();
	for (i = 0; i < n; i++)
	{
		if (nv[i].Luong >= x)
			xuat1NV(nv[i]);
	}
	xuattieudengangdoi();
	
}
void lietke_NS_NV(NhanVien nv[MAX], int&n,unsigned int  v, unsigned int u)
{
	int kq = 0;
	int i;
	for (i = 0; i < n; i++)
		if (u <= nv[i].ntns.namsinh && nv[i].ntns.namsinh <= v)
			kq++;
	if (!kq)
	{
		cout << "\nKhong co Nhan vien co nam sinh trong khoang [ " << u << "..." << v << "]";
	}
	else
	{
		cout << "\nCo " << kq << " Nhan vien co nam sinh trong khoang [ " << u << "..." << v << "]";
		xuattieude();
		for (i = 0; i < n; i++)
			if (u <= nv[i].ntns.namsinh&& nv[i].ntns.namsinh <= v)
			
				xuat1NV(nv[i]);
			
	}
	  xuattieudengangdoi();

}
