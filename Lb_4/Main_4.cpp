#include "fstream"
#include "iostream"
#include <windows.h>
#include "autor.h"
#include "Book.h"
#include "Book_In_Shop.h"
#include "Book_In_library.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char p[20] = "��������";
	char p1[20] = "������";
	char p2[20] = "������ � ���";
	char p3[20] = "��24516";
	autor A(p, p1);
	
	Book_In_Shop book1(100,240,p2, p3, A, 10, 15);
	book1.OutPutShop();

	char* p4 = new char[20];
	strcpy_s(p4, 20, "���� �����-������");
	autor B(p, p1);
	
	Book_In_library book2(123, true, p4, 240, p2, p3, B, 10, 15);
	book2.OutPutLib();

	return 0;
}
