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
	strcpy_s(p, 20,"Крючков");
	
	char p1[20] = "Никита";
	char p2[20] = "Король и Лев";
	char p3[20] = "ВН24516";
	cout << "Cоздание автора Крючка Никиты\n";
	autor A(p, p1);
	cout << "Cоздание книги Король и Лев \n Номер книги ВН24516";
	cout <<	"\n Дата выпуска книги 2010 года \n кол-во страниц: 15\n";
	Book book(p2,p3, A, 2010, 15);
	book.OutPut();
	cout << "Задаем новое название книги: Чертковская рябина\n";
	char p4[20] = "Чертковская рябина";
	book.Set_title(p4);
    delete[] p;
	book.OutPut();

	return 0;
}