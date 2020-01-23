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
	cout << "1-я книга из магазина\n";
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
	strcpy_s(Name, 20, "Граф Монте-Кристо");
	Book_In_library bl(number, avail, Name, cost, a);
	cout << "1-я книга из библиотеки\n";
	bl.OutPutLib();

	cout << "2-я книга из библиотеки\n";
	Book b;
	cin >> b;
	cost = 350;
	Book_In_library bl2(number, avail, Name, cost, b);
	bl2.OutPutLib();
	if (bl < bl2) cout << "оператор сравнения работает\n";


	Book_In_Shop bs2(count, cost, a);
	cout << "2-я книга из магазина\n";
	bs2.OutPutShop();
	if (bs == bs2)cout << "И оператор равенства работает\n";

	count = 327;
	cost = 240;
	Book_In_Shop bs3(count, cost, a);
	cout << "3-я книга из магазина\n";
	bs3.OutPutShop();
	cout << "Складываю 1-ю и 3-ю книгу из магазина\n";
	cout << "Результат: \n";
	(bs + bs3).OutPutShop();

	cout << "Увеличиваю кол-во книг в 1-й книге из магазина с помощью инкремент\n";
	cout << "Результат: \n";
	++bs;
	bs.OutPutShop();

	return;
}