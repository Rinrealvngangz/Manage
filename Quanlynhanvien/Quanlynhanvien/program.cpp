#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
using namespace std;
#include"Thuvien.h"
#include"Menu.h"


void chaychuongtrinh();

int main()
{
	chaychuongtrinh();
	
	return 0;
}

void chaychuongtrinh()
{
	NhanVien nv[MAX];
	
	int n;
	int somenu;
	somenu = 12;
	int menu;
	do {

		menu=Chonmenu(somenu);
		xulymenu(menu,nv,n);
	} while (menu > 0);

	

	_getch();
}