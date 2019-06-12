#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
void chaychuongtrinh();
#include"Thuvien.h"
#include"Menu.h"


int main()
{
	chaychuongtrinh();
	return 0;
}

void chaychuongtrinh()
{
	
	Hanghoa sp[MAX];
	int n;
	int somenu;
	somenu = 10;
	int menu;
	do
	{
		menu = chonmenu(somenu);
		xulymenu(menu, sp, n);

	} while (menu>0);
	
	_getch();
}