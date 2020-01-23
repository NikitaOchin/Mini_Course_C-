#include "Book_In_library.h"

//������������
Book_In_library::Book_In_library() {
	s_name = 1;
	Name = new char[s_name];
	Name[0] = '\0';
}

Book_In_library::Book_In_library(int n, bool a, char* N, double c, int s_n) :number(n), availability(a), Name(N), cost(c)
{
	s_name = s_n;
	Name = new char[s_name];
	strcpy_s(Name, s_name, N);
}

Book_In_library::Book_In_library(int n, bool a, char* N, double c, char* t, char* U, autor& A, int s_t, int s_U, int s_n) :
	Book(t, U, A, s_t, s_U),
	number(n), availability(a), cost(c), Name(N)
{
	s_name = s_n;
	Name = new char[s_name];
	strcpy_s(Name, s_name, N);
}

Book_In_library::Book_In_library(int n, bool a, char* N, double c, Book book, int s_n):
	Book(book),
	number(n), availability(a), cost(c), Name(N)
{
	s_name = s_n;
	Name = new char[s_name];
	strcpy_s(Name, s_name, N);
}

//�������������
Book_In_library::Book_In_library(const Book_In_library& B): Book(B)
{
	s_name = B.s_name;
	Name = new char[s_name];
	strcpy_s(Name, s_name, B.Name);

	number = B.number;
	availability = B.availability;
	cost = B.cost;
}

//����������
Book_In_library::~Book_In_library()
{
	delete[] Name;
}

// - - - - - ������(������ �������) - - - - - -//

void Book_In_library::Set_number(int n)
{
	number = n;
}

const int Book_In_library::Get_number()
{
	return number;
}

void Book_In_library::Set_availability(bool a)
{
	availability = a;
}

const bool Book_In_library::Get_availability()
{
	return availability;
}

void Book_In_library::Set_Name(char* s, int s_n)
{
	s_name = s_n;
	Name = new char[s_name];
	strcpy_s(Name, s_name, s);
}

const char* Book_In_library::Get_Name()
{
	return Name;
}

void Book_In_library::Set_cost(double d)
{
	cost = d;
}

const double Book_In_library::Get_cost()
{
	return cost;
}

// - - - - - �����(������ �������) - - - - - -//


void Book_In_library::OutPut()
{
	//OutPut();
	cout << *this;
	cout << "����� ����� � ����������: \n";
	cout << "����� �����: ";
	cout << Get_number() << "\n";
	cout << "�������: ";
	cout << Get_availability() << "\n";
	cout << "��������: ";
	cout << Get_Name() << "\n";
	cout << "���������: ";
	cout << Get_cost() << "\n\n\n";
}

bool operator<(Book_In_library& B1, Book_In_library& B2)
{
	if (B1.cost < B2.cost)
		return true;
	return false;
}

/*ostream& operator<<(ostream& out, Book_In_library b)
{
	return(
		out << "����� ����� � ����������: \n"
		<< "����� �����: "
		<< b.Get_number() << "\n"
		<< "�������: "
		<< b.Get_availability() << "\n"
		<< "��������: "
		<< b.Get_Name() << "\n"
		<< "���������: "
		<< b.Get_cost() << "\n\n\n");
}
*/