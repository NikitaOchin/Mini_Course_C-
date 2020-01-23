#include "Library.h"
#include "assert.h"




Library::Library()
{
	s_BIL = 1; 
	BIL = new Book_In_library[s_BIL];
}

Library::Library(int n, Book_In_library bil[], int s)
{
	num = n;
	s_BIL = s;
	BIL = new Book_In_library[s_BIL];
	for (int i = 0; i < s;i++)
		BIL[i] = bil[i];
}

Library::~Library()
{
	delete[] BIL;
}


void Library::Set_num(int n)
{
	num = n;
}

int Library::Get_num()
{
	return num;
}

void Library::Set_BIL(Book_In_library bil[], int s)
{
	if (s != -1) { s_BIL = s; BIL = new Book_In_library[s_BIL]; }
	for (int i = 0; i < s_BIL;i++)
		BIL[i] = bil[i];
}

Book_In_library* Library::Get_BIL()
{
	return BIL;
}

void Library::Set_s_BIL(int s)
{
	s_BIL = s;
}

int Library::Get_s_BIL()
{
	return s_BIL;
}

Book_In_library& Library::operator[](int i)
{
	assert(i >= 0 && i < s_BIL);
	return BIL[i];
}
