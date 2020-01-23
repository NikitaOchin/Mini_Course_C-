#pragma once
#include "Book.h"
#include "autor.h"
#include "assert.h"
#include "iostream"

class Book_In_Shop :
	public Book
{
public:
	Book_In_Shop() {};
	Book_In_Shop(Book book): Book(book){}
	Book_In_Shop(int Count, double Cost) :count(Count), cost(Cost) {};
	Book_In_Shop(int Count, double Cost, char* t, char* U, autor& A, int s_t = 20, int s_U = 20);
	Book_In_Shop(int Count, double Cost, Book book);

	~Book_In_Shop();

private:
	int count;
	double cost;

public:
	void Set_count(int);
	const int Get_count();

	void Set_cost(double);
	const double Get_cost();

	const Book_In_Shop& operator++() { ++count; return*this; };
	Book_In_Shop operator+(Book_In_Shop& Book);
	void OutPut();

};

