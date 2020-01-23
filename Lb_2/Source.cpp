#include "fstream"
#include "iostream"
#include <windows.h>
using namespace std;

struct autor
{
	string last_name;
	double salary;
};

struct list {
	autor autor;
	int k;
	list* ps;
};

list* Create_AutorList(int);
inline list* Add_NewAutor_inList(list*, autor);
list* Add_K_NewAutor_inList(list*, autor, int);
list* DELETE_K_NewAutor_inList(list*, int);
list* CHANGE_K_J(list*, int, int);
autor InPut();
const void OutPut(list*);
const void File_write_List(list* L, string Filename);
const int Eguals_Salary_List(double, list*);
void Test_AutorList();


int main() {
	Test_AutorList();
	return 0;
}

void Test_AutorList() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "�������� ������ � ���������� ������\n";
	cout << "������� ���-�� �������:";
	int count; cin >> count;
	list* L = Create_AutorList(count);
	count = L->k + 1;

	cout << "�������� ������� ������:\n";
	OutPut(L);

	cout << "�������� ������� ���������� ������ ������ � ����� ������ ������\n";
	cout << "������� ������� ������:";
	string s; cin >> s;
	cout << "������� �������:";
	double g; cin >> g;
	autor A1{ s,g };
	L = Add_NewAutor_inList(L, A1);//���������� ������ ������ � ����� ������ ������
	count = L->k + 1;

	cout << "�������� ������� �������� ���-�� ������� � �������� ���������\n";
	autor* A = new autor;
	cout << "������� �������:";
	double sal; cin >> sal;
	cout << "�������� ���-�� �������� ������� sal:";
	cout << Eguals_Salary_List(sal, L);

	cout << "\n�������� ������� ���������� ������ �������� �� k-� �����\n";
	cout << "�� ����� ����� �� ������ ��������� ������ ������:";
	int k; cin >> k;
	cout << "������� ������� ������:";
	s; cin >> s;
	cout << "������� �������:";
	g; cin >> g;
	L = Add_K_NewAutor_inList(L, autor{ s,g }, k);
	count = L->k + 1;

	cout << "�������� ������� �������� k-�� ��������\n";
	cout << "������� ����� ������, �������� �� ������ �������:";
	cin >> k;
	L = DELETE_K_NewAutor_inList(L, k);
	count = L->k + 1;

	cout << "�������� ������� �������� �-� � j-� �������� ������\n";
	cout << "������� ����� �������, ������� �� ������ �������� �������:";
	int j;cin >> j;
	cin>>k;
	CHANGE_K_J(L, k, j);
	OutPut(L);

	cout << "�������� ������� ������ ������ � ���� SpisokFile.txt\n";
	File_write_List(L, "SpisokFile.txt");

	return;

}

list* Create_AutorList(int count)
{
	list* HEAD = new list;
	HEAD->autor = InPut();
	HEAD->k = 0;
	HEAD->ps = NULL;
	
	int i = 1;
	while (i < count) {
		list* L = new list;
		L->autor = InPut();
		L->k = i;
		L->ps = HEAD;
		HEAD = L;
		i++;
	}
	return HEAD;
}

inline list* Add_NewAutor_inList(list* L, autor A) {
	return new list{ A, L->k + 1, L };
}

list* Add_K_NewAutor_inList(list* L, autor A, int t) {
	list* L1 = new list{ A,t+1,0 };
	if (t == L->k) {
		L1->ps = L;
		return L1;
	}
	list* p = L;
	while (p->k != t+1) {
		p->k++;
		p = p->ps;
	}
	p->k++;
	L1->ps = p->ps;
	p->ps = L1;
	return L;
}

list* DELETE_K_NewAutor_inList(list* L, int k) {
	if (k == L->k) 
		return L->ps;
	list* p = L;
	p->k--;
	while (p->k != k) {
		p = p->ps;
		p->k--;
	}
	list* L1 = p->ps->ps;
	delete p->ps;
	p->ps = L1;
	return L;
}

list* CHANGE_K_J(list* L, int k,int j) {
	int M = max(k, j);
	int m = min(k, j);
	if (m == M) return L;
	list* J = L;
	while (J->k != M) 
		J = J->ps;
	list* K = J;
	while (K->k != m) {
		K = K->ps;
	}
	list* T = new list;
	T->autor= K->autor;
	K->autor = J->autor;
	J->autor = T->autor;
	delete T;
	T = 0;
	return L;
}

autor InPut() {
	autor a;
	cout << "������� �������: ";
	cin >> a.last_name;
	cout << "������� �������: ";
	cin >> a.salary;
	return a;
}

const void OutPut(list* L) {
	list* p = L;
	while (p != NULL) {
		cout << p << " \n";
		cout << p->autor.last_name << " \n";
		cout << p->autor.salary << " \n";
		cout << p->k << "\n\n";
		p = p->ps;
	}
}

const void File_write_List(list* L, string FileName) {
	list* p = L;
	ofstream fout(FileName);
	while(p!=NULL) {
		fout << p->autor.last_name << " " << p->autor.salary << "\n";
		p = p->ps;
	}
	fout.close();

}

const int Eguals_Salary_List(double sal, list* L) {
	list* p = L;
	int k = 0;
	while (p != NULL) {
		if (p->autor.salary == sal)
			k++;
		p = p->ps;
	}
	return k;
}