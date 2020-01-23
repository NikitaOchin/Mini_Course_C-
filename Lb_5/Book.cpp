#include "Book.h"
#include "autor.h"
#include "iostream"
#include "assert.h"

using namespace std;

Book::Book()
{
	s_title = 20;
	title = new char[s_title];
	title[0] = '\0';
	s_UDK = 20;
	UDK = new char[s_UDK];
	UDK[0] = '\0';
	autor_c = new autor();
}

Book::Book(char* t, char* U, autor& a, int d, int p, int s_t, int s_U)
{
	s_title = s_t;
	title = new char[s_title];
	strcpy_s(title, s_title, t);
	
	s_UDK = s_U;
	UDK = new char[s_UDK];
	strcpy_s(UDK, s_UDK, U);
	
	autor_c = new autor(a);
	date = d;
	page = p;
}

Book::Book(const Book& B)
{
	s_title = B.s_title;
	title = new char[s_title];
	strcpy_s(title, s_title, B.title);

	s_UDK = B.s_UDK;
	UDK = new char[s_UDK];
	strcpy_s(UDK, s_UDK, B.UDK);
	
	autor_c = new autor(*B.autor_c);
	date = B.date;
	page = B.page;
}

Book::~Book() {
	delete[] title;
	delete[] UDK;
	delete autor_c;
}


void Book::Set_title(char* t, int s_t)
{
	s_title = s_t;
	title = new char[s_title];
	strcpy_s(title, s_title, t);
}

const char* Book::Get_title()
{
	return title;
}


void Book::Set_UDK(char* udk, int s_udk)
{
	s_UDK = s_udk;
	UDK = new char[s_UDK];
	strcpy_s(UDK, s_UDK, udk);
}

const char* Book::Get_UDK()
{
	return UDK;
}


void Book::Set_autor_c(autor &a)
{
	*autor_c = a;
}

const autor& Book::Get_autor_c()
{
	return *autor_c;
}


void Book::Set_date(int d)
{
	date = d;
}

const int Book::Get_date()
{
	return date;
}


void Book::Set_page(int p)
{
	page = p;
}

const int Book::Get_page()
{
	return page;
}


void Book::OutPut()
{
	cout << "Вывод книги в полном виде: \n";
	cout << "Название: ";
	cout << Get_title() << "\n";
	cout << "Код товара: ";
	cout << Get_UDK() << "\n";
	cout << "Автор: ";
	autor A(Get_autor_c());
	cout << A.Get_last_name() << " " << A.Get_name() << "\n";
	cout << "Дата выпуска: ";
	cout << Get_date() << "\n";
	cout << "Кол-во страниц: ";
	cout << Get_page() << "\n\n\n";
}


bool operator==(Book& B1, Book& B2)
{
	bool b1 = *B1.Get_UDK() == *B2.Get_UDK();
	bool b2 = B1.Get_date() == B2.Get_date();
	bool b3 = B1.Get_page() == B2.Get_page();
	bool b4 = *B1.Get_title() == *B2.Get_title();
	autor A1(B1.Get_autor_c()); autor A2(B2.Get_autor_c());
	bool b5 = *A1.Get_last_name() == *A2.Get_last_name();
	bool b6 = *A1.Get_name() == *A2.Get_name();
	return b1 && b2 && b3 && b4 && b5 && b6;
}

ostream& operator<<(ostream& out, Book b)
{
	return(
	out << "Вывод книги в полном виде: \n"
	<< "Название: " << b.title << "\n"
    << "Код товара: " << b.UDK << "\n"
	//<< "Автор: "<< b.autor_c->Get_last_name() << " " << b.autor_c->Get_name() << "\n"
	<< "Автор: "<< *b.autor_c
	<< "Дата выпуска: "	<< b.date << "\n"
	<< "Кол-во страниц: " << b.page << "\n\n\n");
}

istream& operator>>(istream& in, Book& b)
{
	return(
		cout <<"\nНазвание: ", in >> b.title,
		cout <<"\nКод товара: ", in >> b.UDK,
		cout <<"\nАвтор:\n", in >> *b.autor_c,
		cout <<"\nГод выпуска: ", in >> b.date,
		cout <<"\nКол-во страниц: ", in >> b.page
		);
}