#include "autor.h"
#include "Book.h"
#include "fstream"
#include "iostream"
#include <windows.h>

using namespace std;

void OutPut(Book&);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* p = new char[20];
	strcpy_s(p, 20,"�������");
	
	char p1[20] = "������";
	char p2[20] = "������ � ���";
	char p3[20] = "��24516";
	cout << "C������� ������ ������ ������\n";
	autor A(p, p1);
	cout << "C������� ����� ������ � ��� \n ����� ����� ��24516";
	cout <<	"\n ���� ������� ����� 2010 ���� \n ���-�� �������: 15\n";
	Book book(p2,p3, A, 2010, 15);
	book.OutPut();
	cout << "������ ����� �������� �����: ����������� ������\n";
	char p4[20] = "����������� ������";
	book.Set_title(p4);
    delete[] p;
	book.OutPut();

	return 0;
}