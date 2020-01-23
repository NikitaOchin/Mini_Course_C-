#include "autor.h"
#include "iostream"
using namespace std;

autor::autor()
{
	s_last_name = 20;
	s_name = 20;
	name = new char[s_last_name];
	name[0] = '\0';
	last_name = new char[s_name];
	last_name[0] = '\0';
}

autor::autor(char* l_n, char* n, int s_ln, int s_n)
{
	s_last_name = s_ln;
	last_name = new char[s_last_name];
	strcpy_s(last_name, s_last_name, l_n);
	
	s_name = s_n;
	name = new char[s_name];
	strcpy_s(name, s_name, n);
}

autor::autor(const autor& A)
{
	s_last_name = A.s_last_name;
	last_name = new char[s_last_name];
	strcpy_s(last_name, s_last_name, A.last_name);

	s_name = A.s_name;
	name = new char[s_name];
	strcpy_s(name, s_name, A.name);
}

autor::~autor()
{
	delete[] last_name;
	delete[] name;
}


void autor::Set_last_name(char* l_n, int s_ln) {
	s_last_name = s_ln;
	last_name = new char[s_last_name];
	strcpy_s(last_name, s_last_name, l_n);
}

char* autor::Get_last_name() {
	return last_name;
}


void autor::Set_name(char* n, int s_n) {
	s_name = s_n;
	name = new char[s_name];
	strcpy_s(name, s_name, n);
}

char* autor::Get_name() {
	return name;
}

ostream& operator<<(ostream& out, autor a)
{
	return(out << "јвтор: " << a.last_name << " " << a.name << "\n");
}

istream& operator>>(istream& in, autor& a)
{
	return(cout << "¬ведите фамилию: ", in  >> a.last_name, cout << "\n¬ведите им€: ", in >> a.name);
}
