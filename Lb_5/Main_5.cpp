#include "fstream"
#include "iostream"
#include <windows.h>
#include "autor.h"
#include "Book.h"
#include "Book_In_Shop.h"
#include "Book_In_library.h"

using namespace std;

void Test_Lb_5();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test_Lb_5();
	return 0;
}

void Test_Lb_5() {
	cout << "1-� ����� �� ��������\n";
	Book a;
	cin >> a;
	int count = 100;
	double cost = 240;

	Book_In_Shop bs(count, cost, a);
	bs.OutPutShop();

	int number = 200;
	bool avail = true;
	char* Name = new char[30];
	cost = 140;
	strcpy_s(Name, 20, "���� �����-������");
	Book_In_library bl(number, avail, Name, cost, a);
	cout << "1-� ����� �� ����������\n";
	bl.OutPutLib();

	cout << "2-� ����� �� ����������\n";
	Book b;
	cin >> b;
	cost = 350;
	Book_In_library bl2(number, avail, Name, cost, b);
	bl2.OutPutLib();
	if (bl < bl2) cout << "�������� ��������� ��������\n";


	Book_In_Shop bs2(count, cost, a);
	cout << "2-� ����� �� ��������\n";
	bs2.OutPutShop();
	if (bs == bs2)cout << "� �������� ��������� ��������\n";

	count = 327;
	cost = 240;
	Book_In_Shop bs3(count, cost, a);
	cout << "3-� ����� �� ��������\n";
	bs3.OutPutShop();
	cout << "��������� 1-� � 3-� ����� �� ��������\n";
	cout << "���������: \n";
	(bs + bs3).OutPutShop();

	cout << "���������� ���-�� ���� � 1-� ����� �� �������� � ������� ���������\n";
	cout << "���������: \n";
	++bs;
	bs.OutPutShop();

	return;
}