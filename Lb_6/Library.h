#pragma once
#include "Book_In_library.h"


class Library
{
public:
	Library();
	Library(int n, Book_In_library bil[], int s);
	~Library();

private:
	int num;
	Book_In_library* BIL;
	int s_BIL;

public:
	void Set_num(int);
	int Get_num();
	void Set_BIL(Book_In_library[], int s = -1);
	Book_In_library* Get_BIL();
	void Set_s_BIL(int);
	int Get_s_BIL();

	Book_In_library& operator[](int i);
};