#pragma once
#include "autor.h"
#include "iostream"
using namespace std;

class Book
{
public:
	Book();
	Book(char*, char*, autor&, int, int, int = 20, int = 20);
	Book(const Book& B);
	~Book();

protected:
	char* title;
	char* UDK;
	int s_title, s_UDK;
	autor* autor_c;
	int date;
	int page;

public:
	void Set_title(char*, int = 20);
	const char* Get_title();

	void Set_UDK(char*, int = 20);
	const char* Get_UDK();

	void Set_autor_c(autor&);
	const autor& Get_autor_c();

	void Set_date(int);
	const int Get_date();

	void Set_page(int);
	const int Get_page();

	friend bool operator==(Book&, Book&);

	friend ostream& operator<<(ostream& out, Book);
	friend istream& operator>>(istream& in, Book& b);

	void OutPut();
};

