#define MAX 100
#define KENGANG '='
typedef unsigned short int Byte;


struct Ngaythangnam
{
	Byte ngay;
	Byte thang;
	unsigned int nam;
};
struct Hanghoa
{
	char Tenmathang[MAX];
	long int  Dongia;
	int Soluong;
	char  Donvi[MAX];
	Ngaythangnam ntn;
	char Loaimathang[MAX] ;
	
};

void xuatkengang();
int Taodanhsach(char *filename ,Hanghoa sp[MAX], int &n)
{
	
	ifstream in(filename);
	if (!in)
	{

		cout << "\nLoi mo file.";
		return 0;
	}

	char Tenmathang[MAX];
	long int Dongia;
	int Soluong;
	char  Donvi[MAX];
	char Loaimathang[MAX];
	int ngaysp, thangsp, namsp;

	n = 0;
	
	in >> Tenmathang; strcpy_s(sp[n].Tenmathang, Tenmathang);
	in >> Dongia; sp[n].Dongia = Dongia;
	in >> Soluong; sp[n].Soluong = Soluong;
	in >> Donvi; strcpy_s(sp[n].Donvi, Donvi);
	in >> ngaysp; sp[n].ntn.ngay = ngaysp;
	in >> thangsp; sp[n].ntn.thang = thangsp;
	in >> namsp; sp[n].ntn.nam = namsp;
	in >> Loaimathang; strcpy_s(sp[n].Loaimathang, Loaimathang);

		while (!in.eof())
		{
			n++;
			in >> Tenmathang; strcpy_s(sp[n].Tenmathang, Tenmathang);
			in >> Dongia; sp[n].Dongia = Dongia;
			in >> Soluong; sp[n].Soluong = Soluong;
			in >> Donvi; strcpy_s(sp[n].Donvi, Donvi);
			in >> ngaysp; sp[n].ntn.ngay = ngaysp;
			in >> thangsp; sp[n].ntn.thang = thangsp;
			in >> namsp; sp[n].ntn.nam = namsp;
			in >> Loaimathang; strcpy_s(sp[n].Loaimathang, Loaimathang);
		}
		
		in.close();
	}

void xuattieude()
{
	xuatkengang();
	cout << "\n";
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(16) << "Ten mat hang"
		<< setw(15) << "Don Gia"
		<< setw(10) << "So Luong"
		<< setw(10) <<  "Don Vi"
		<< setw(6) <<  "Ngay" 
		<< setw(6) <<  "Thang"
		<< setw(10) <<  "Nam"
		<< setw(5) <<  "Loai"
		<< ':';

}
void xuatkengang()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left)
		<< ':';
	for (i = 0; i < 78; i++)
		cout << KENGANG;
	cout << ':';
}
void xuat1SP(Hanghoa &p )
{
	cout << "\n";
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(16) << p.Tenmathang
		<< setw(15) << p.Dongia
		<< setw(10) << p.Soluong
		<< setw(10) << p.Donvi
		<< setw(6) << p.ntn.ngay
		<< setw(6) << p.ntn.thang
		<< setw(11) << p.ntn.nam
		<< setw(1) << p.Loaimathang
		<< ':';
	cout << endl;

}
void xuatDSSP(Hanghoa sp[MAX], int n)
{
	int i;
	xuattieude();
	for (i = 0; i < n; i++)
	{
		xuat1SP(sp[i]);
		if ((i + 1) % 5==0)
			xuatkengang();
		
	}
	xuatkengang();
	
}
void hoanvi(Hanghoa&p, Hanghoa&q)
{
	Hanghoa t;
	t = p;
	p = q;
	q = t;
}

void sapxep_ten_theo_ABC(Hanghoa sp[MAX], int n,char Tenmathang[MAX])
{
	int i,j;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)

			if (_strcmpi(sp[i].Tenmathang, sp[j].Tenmathang) > 0)
				hoanvi(sp[i], sp[j]);

}

long int Tinh_Tong_Don_Gia(Hanghoa sp[MAX], int n)
{
	int i;
	long int sum=0;
	for (i = 0; i < n; i++)
		sum += sp[i].Dongia;
	return sum;
}
void  Giatri_Max_mat_hang(Hanghoa sp[MAX], int n)
{
	int Max;
	int i;
	Max = sp[0].Dongia;
	for (i = 0; i < n; i++)
	{
		if (Max <= sp[i].Dongia)
			Max = sp[i].Dongia;
		
	}
	xuattieude();
	for (i = 0; i < n; i++)
		if (Max <= sp[i].Dongia)
		{
			xuat1SP(sp[i]);
		}
	xuatkengang();
}

void xuatcacmathang_hethansudung(Hanghoa sp[MAX], int n, int ngay, int thang, int nam)
{
	int i;
	xuattieude();
	xuatkengang();
	for (i = 0; i < n; i++)
	{
		if (sp[i].ntn.ngay < ngay || sp[i].ntn.thang < thang || sp[i].ntn.nam < nam)
			xuat1SP(sp[i]);
	}
	xuatkengang();
}
void sapxep_xuat_theotungloai(Hanghoa sp[MAX], int n)
{
	int i, j, dau, m = 0,dem = 0;
	Hanghoa spp[MAX];
	int vt[MAX];
	for (i = 0; i < n; i++)
	{
		dau = 1;
		for (j = 0; j < m&&dau; j++)
		
			dau = dau && (_strcmpi(sp[i].Loaimathang, spp[j].Loaimathang) !=0);
		if (dau)
		{
			strcpy_s(spp[m++].Loaimathang, MAX, sp[i].Loaimathang);
			vt[m] = i;
			dem++;
		}

	}
	m = 1;
	xuattieude();
	xuatkengang();
	while (m<=dem)
	{
		for (i = 0; i < n; i++)
		{
			if (_strcmpi(sp[i].Loaimathang, sp[vt[m]].Loaimathang) == 0)
				xuat1SP(sp[i]);
		}
		if (m < dem)
		{
			xuatkengang();
		}
		m++;
	};
	xuatkengang();
}
void tim_hang_khongqua30day(Hanghoa sp[MAX], int n,int ngay,int thang,int nam)
{
	int  i;
	int dk;
	xuattieude();
	xuatkengang();
	for (i = 0; i < n; i++)
	{
		dk = (sp[i].ntn.ngay == ngay) && (sp[i].ntn.nam == nam)&&
			(sp[i].ntn.thang > thang) &&( sp[i].ntn.thang==thang+1)  ;
		
		if(dk)
			xuat1SP(sp[i]);
		
	}
	xuatkengang();

}

void xoasp(Hanghoa sp[MAX], int &n, char Tenmathang[MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		if (strcmp(sp[i].Tenmathang, Tenmathang) == 0)
			break;
	if (i == n)
	{
		cout << "\nKhong co mat hang can xoa";
		
	}
		for (j = i + 1; j < n; j++)
		       sp[j - 1] = sp[j];
	n--;

}
int tinhsoluong_keo(Hanghoa sp[MAX], int n,char loaimathang[MAX])

{
	loaimathang = { "Keo" };
	
	int i;
	int dk;
	int sum1 = 0;
	for (i = 0; i < n; i++)
	{
		dk = (strcmp(sp[i].Loaimathang, loaimathang) == 0);
		
		if (dk)
		
			sum1 += sp[i].Soluong;
		
	}
	
	return sum1;
}
int tinhsoluong_banh(Hanghoa sp[MAX], int n, char loaimathang[MAX])

{
	loaimathang = { "Banh" };

	int i;
	int dk;
	int sum2 = 0;
	for (i = 0; i < n; i++)
	{
		dk = (strcmp(sp[i].Loaimathang, loaimathang) == 0);
		
		if (dk)

			sum2 += sp[i].Soluong;

	}

	return sum2;
}

int tinhsoluong_banh_keo(Hanghoa sp[MAX],int n,char loaimathang[MAX])
{
	int sum = 0;
	int sum1;
	int sum2;
	sum1 = tinhsoluong_keo(sp, n, loaimathang);
	sum2 = tinhsoluong_banh(sp, n, loaimathang);
	sum = sum1 + sum2;
	return sum;
}

void tim_bia_re(Hanghoa sp[MAX], int n,char loaimathang[MAX])
{
	int i;
	int dk;
	long int min;
	loaimathang = { "Bia" };
	min = sp[0].Dongia;
	xuattieude();
	xuatkengang();
	for (i = 0; i < n; i++)
	{
		dk = (strcmp(sp[i].Loaimathang, loaimathang) == 0);
		if (dk && min >= sp[i].Dongia)
		{
			min == sp[i].Dongia;

			xuat1SP(sp[i]);
		}
	}
	xuatkengang();
}