#include "Book_In_Shop.h"


Book_In_Shop::Book_In_Shop(int Count, double Cost, Book book) :
	Book(book),
	count(Count), cost(Cost)
{}

Book_In_Shop::Book_In_Shop(int Count, double Cost, char* t, char* U, autor& A, int s_t, int s_U) :
	Book(t, U, A, s_t, s_U),
	count(Count), cost(Cost)
{}

Book_In_Shop::~Book_In_Shop()
{
}

void Book_In_Shop::Set_count(int c)
{
	count = c;
}

const int Book_In_Shop::Get_count()
{
	return count;
}

void Book_In_Shop::Set_cost(double c)
{
	cost = c;
}

const double Book_In_Shop::Get_cost()
{
	return cost;
}

Book_In_Shop Book_In_Shop::operator+(Book_In_Shop& book)
{
	//assert(*book.Get_title() == *Get_title
	assert(book == *this);
	Book_In_Shop SCB(book);
	SCB.count = count + book.count;
	return SCB;
}

void Book_In_Shop::OutPutShop()
{
	//OutPut();
	cout << *this;
	cout << "Вывод книги в магазине: \n";
	cout << "Количество: ";
	cout << Get_count() << "\n";
	cout << "Стоимость: ";
	cout << Get_cost() << "\n\n";
}
