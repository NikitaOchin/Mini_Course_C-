#include "fstream"
#include "iostream"
#include <windows.h>
using namespace std;

struct autor
{
	string last_name;
	double salary;
};

void Menu();
inline autor* Create_Autor_arr(int);
void OutPut_Autor_arr(autor*, int);
void InPut_Autor_arr(autor*, int);
int Eguals_Salary_Autor_arr(double, autor*, int);
void Sort_Sal_Autor_arr(autor*, int);
void file_write_Autor_arr(autor*, int, string);
autor* Add_Autor_arr(int, autor, autor*, int&);
autor* Delete_Autor_arr(int, autor*, int&);
void Test_Autor_arr();
void Test_Autor_arrFP();


int main() {
	Test_Autor_arrFP();
	return 0;
}

void Test_Autor_arrFP() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = 0;
	autor* Autor_arr = 0;

	cout << "�������� ������� �� ������� ������� �������\n";
	delete[] Autor_arr;
	Autor_arr = 0;
	cout << "\n������� ���-�� ����� �������: ";
	cin >> count;
	Autor_arr = Create_Autor_arr(count);
	InPut_Autor_arr(Autor_arr, count);

	cout << "\n�������� ������� ������\n";
	OutPut_Autor_arr(Autor_arr, count);

	cout << "\n�������� ������� �������� ������� ������� �������� �������\n";
	double sal;
	cout << "������� �������: ";
	cin >> sal;
	cout << "\n���-�� ������� ������� ������� � ������� " << sal << " �����: ";
	cout << Eguals_Salary_Autor_arr(sal, Autor_arr, count) << "\n";
	
	cout << "\n�������� ���������� �� ��������\n";
	Sort_Sal_Autor_arr(Autor_arr, count);
	OutPut_Autor_arr(Autor_arr, count);

	cout << "\n�������� ������ ������� ���������� ������ ������ � ������ ����� k-�� ������\n";
	int k;
	autor* A = new autor[1];
	cout << "������� ����� ������, ����� �������� �� ������ �������� ������: ";
	cin >> k;
	InPut_Autor_arr(A, 1);
	Autor_arr = Add_Autor_arr(k, *A, Autor_arr, count);

	cout << "\n�������� ������ ������� �������� k-�� ������ �� �������\n";
	int n7;
	cout << "������� ����� ������, �������� �� ������ �������: ";
	cin >> n7;
	Autor_arr = Delete_Autor_arr(n7, Autor_arr, count);

	cout << "\n������ ������� � ���� AutorFile.txt\n";
	file_write_Autor_arr(Autor_arr, count, "AutorFile.txt");
}
void Test_Autor_arr() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int count = 0;
	autor* Autor_arr = 0;
	int p;
	while (true) {
		Menu();
		cin >> p;
		switch (p) {
		case 1:
		{
			delete[] Autor_arr;
			Autor_arr = 0;
			cout << "\n������� ���-�� ����� �������: ";
			cin >> count;
			Autor_arr = Create_Autor_arr(count);
			InPut_Autor_arr(Autor_arr, count);
		}
		break;
		case 2:
			OutPut_Autor_arr(Autor_arr, count);
			break;
		case 3:
		{
			double sal;
			cout << "������� �������: ";
			cin >> sal;
			cout << "\n���-�� ������� ������� ������� � ������� " << sal << " �����: ";
			cout << Eguals_Salary_Autor_arr(sal, Autor_arr, count) << "\n";
		}
		break;
		case 4:
			Sort_Sal_Autor_arr(Autor_arr, count);
			OutPut_Autor_arr(Autor_arr, count);
			break;
		case 5:
			file_write_Autor_arr(Autor_arr, count, "AutorFile.txt");
			break;
		case 6:
		{
			int k;
			autor* A = new autor[1];
			cout << "������� ����� ������, ����� �������� �� ������ �������� ������: ";
			cin >> k;
			InPut_Autor_arr(A, 1);
			Autor_arr = Add_Autor_arr(k, *A, Autor_arr, count);
		}
		break;
		case 7:
		{
			int n7;
			cout << "������� ����� ������, �������� �� ������ �������: ";
			cin >> n7;
			Autor_arr = Delete_Autor_arr(n7, Autor_arr, count);
		}
		break;
		default:
			delete[] Autor_arr;
			Autor_arr = 0;
			return;
		}
	}
}

void Menu()
{
	cout << "\n1.������� ������ �������\n";
	cout << "2. ������� ���������� �������\n";
	cout << "3. ������� ������� ������� �������� �������\n";
	cout << "4. ���������� ������� �� ������� ��������\n";
	cout << "5. �������� ��� � ����\n";
	cout << "6. �������� ������ ������ � ������ ����� k-�� ������\n";
	cout << "7. ������� k-�� ������ �� �������\n";
	cout << "0.�����\n";
}

inline autor* Create_Autor_arr(int count) {
	return new autor[count];
}

void InPut_Autor_arr(autor* A, int count)
{
	for (int i = 0;i < count;i++)
	{
		cout << "\n������� ������� ������: ";
		cin >> A[i].last_name;
		cout << "������� ������� ����� ������: ";
		cin >> A[i].salary;
	}
}

void OutPut_Autor_arr(autor* A, int count) {
	for (int i = 0;i < count;i++)
	{
		cout << "\n������� " << i + 1 << "-�� ������: " << A[i].last_name << ".";
		cout << "\n��� �������: " << A[i].salary << "\n";
	}
}

int Eguals_Salary_Autor_arr(double sal, autor* A, int count) {
	int p = 0;
	for (int i = 0; i < count; i++)
		if (A[i].salary == sal)
			p++;
	return p;
}

void Sort_Sal_Autor_arr(autor* A, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (A[j].salary > A[j + 1].salary) {
				autor temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

void file_write_Autor_arr(autor* Autor_arr, int count, string FileName)
{
	ofstream fout(FileName);
	for (int i = 0; i < count;i++)
		fout << i << " " << Autor_arr[i].last_name << " " << Autor_arr[i].salary << "\n";
	fout.close();
}

autor* Add_Autor_arr(int k, autor A, autor* Autor_arr, int& count)
{
	autor* a = new autor[++count];
	for (int i = 0;i < k;i++) {
		a[i] = Autor_arr[i];
	}
	a[k] = A;
	for (int i = k + 1;i < count;i++) {
		a[i] = Autor_arr[i - 1];
	}
	return a;
}

autor* Delete_Autor_arr(int k, autor* Autor_arr, int& count)
{
	autor* a = new autor[--count];
	for (int i = 0;i < k - 1;i++) {
		a[i] = Autor_arr[i];
	}
	for (int i = k - 1; i < count; i++) {
		a[i] = Autor_arr[i + 1];
	}
	return a;
}