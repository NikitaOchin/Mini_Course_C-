#include "Library.h"

#include "iostream"
#include <windows.h>
#include "autor.h"
#include "Book.h"
#include "Book_In_Shop.h"
#include "Book_In_library.h"

using namespace std;

void Test_Lb_5();
void Test_Lb_6();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test_Lb_6();
	return 0;
}

void Test_Lb_6() {
	int count = 2;
	//�������� ������ �� ����������
	Book_In_library* BIL = new Book_In_library[count];
	cin >> BIL[0];	
	BIL[0].Set_number(12);
	BIL[0].Set_availability(true);
	char D[20] = "������";
	BIL[0].Set_Name(D);
	BIL[0].Set_cost(1500);
	
	cin >> BIL[1];
	BIL[1].Set_number(42);
	BIL[1].Set_availability(true);
	char G[20] = "�������";
	BIL[1].Set_Name(G);
	BIL[1].Set_cost(4670);

	//�������� ������ �� ��������
	Book_In_Shop BIP = Book_In_Shop(340, 160, BIL[0]);

	//�������� ����������
	Library L;
	L.Set_BIL(BIL, 2);

	//�������� ��������� ������
	Book* B[3];
	
	//���������� �������� �� ����������
	for (int i = 0; i < L.Get_s_BIL();i++)
		B[i] = new Book_In_library(L[i]);
	
	//���������� �������� �� ��������
	B[2] = new Book_In_Shop(BIP);
	
	//����� ���������
	for (int i = 0; i < 3;i++)
		B[i]->OutPut();
	
	return;
}

void Test_Lb_5() {
	cout << "1-� ����� �� ��������\n\n";
	Book a;
	cin >> a;
	int count = 100;
	double cost = 240;

	Book_In_Shop bs(count, cost, a);
	bs.OutPut();

	int number = 200;
	bool avail = true;
	char* Name = new char[30];
	cost = 140;
	strcpy_s(Name, 20, "���� �����-������");
	Book_In_library bl(number, avail, Name, cost, a);
	cout << "1-� ����� �� ����������\n\n";
	bl.OutPut();

	cout << "2-� ����� �� ����������\n\n";
	Book b;
	cin >> b;
	cost = 350;
	Book_In_library bl2(number, avail, Name, cost, b);
	bl2.OutPut();
	if (bl < bl2) cout << "�������� ��������� ��������\n\n";


	Book_In_Shop bs2(count, cost, a);
	cout << "2-� ����� �� ��������\n\n";
	bs2.OutPut();
	if (bs == bs2)cout << "� �������� ��������� ��������\n\n";

	count = 327;
	cost = 240;
	Book_In_Shop bs3(count, cost, a);
	cout << "3-� ����� �� ��������\n\n";
	bs3.OutPut();
	cout << "��������� 1-� � 3-� ����� �� ��������\n\n";
	cout << "���������: \n";
	(bs + bs3).OutPut();

	cout << "���������� ���-�� ���� � 1-� ����� �� �������� � ������� ���������\n\n";
	cout << "���������: \n";
	++bs;
	bs.OutPut();

	return;
}