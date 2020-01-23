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

	cout << "Проверка функции на создане массива авторов\n";
	delete[] Autor_arr;
	Autor_arr = 0;
	cout << "\nВведите кол-во новых авторов: ";
	cin >> count;
	Autor_arr = Create_Autor_arr(count);
	InPut_Autor_arr(Autor_arr, count);

	cout << "\nПроверка функции вывода\n";
	OutPut_Autor_arr(Autor_arr, count);

	cout << "\nПроверка функции подсчета авторов имеющих заданный гонорар\n";
	double sal;
	cout << "Введите гонорар: ";
	cin >> sal;
	cout << "\nКол-во авторов имеющих гонорар в размере " << sal << " равно: ";
	cout << Eguals_Salary_Autor_arr(sal, Autor_arr, count) << "\n";
	
	cout << "\nПроверка сортировки по гонарару\n";
	Sort_Sal_Autor_arr(Autor_arr, count);
	OutPut_Autor_arr(Autor_arr, count);

	cout << "\nПроверка работы функции добавления нового автора в массив после k-го автора\n";
	int k;
	autor* A = new autor[1];
	cout << "Введите номер автора, после которого вы хотите добавить нового: ";
	cin >> k;
	InPut_Autor_arr(A, 1);
	Autor_arr = Add_Autor_arr(k, *A, Autor_arr, count);

	cout << "\nПроверка работы функции удаления k-го автора из массива\n";
	int n7;
	cout << "Введите номер автора, которого вы хотите удалить: ";
	cin >> n7;
	Autor_arr = Delete_Autor_arr(n7, Autor_arr, count);

	cout << "\nЗапись массива в файл AutorFile.txt\n";
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
			cout << "\nВведите кол-во новых авторов: ";
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
			cout << "Введите гонорар: ";
			cin >> sal;
			cout << "\nКол-во авторов имеющих гонорар в размере " << sal << " равно: ";
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
			cout << "Введите номер автора, после которого вы хотите добавить нового: ";
			cin >> k;
			InPut_Autor_arr(A, 1);
			Autor_arr = Add_Autor_arr(k, *A, Autor_arr, count);
		}
		break;
		case 7:
		{
			int n7;
			cout << "Введите номер автора, которого вы хотите удалить: ";
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
	cout << "\n1.Создать массив авторов\n";
	cout << "2. Вывести содержимое массива\n";
	cout << "3. Подсчет авторов имеющих заданный гонорар\n";
	cout << "4. Сортировка массива по размеру гонорара\n";
	cout << "5. Записать все в файл\n";
	cout << "6. Добавить нового автора в массив после k-го автора\n";
	cout << "7. Удалить k-го автора из массива\n";
	cout << "0.Выйти\n";
}

inline autor* Create_Autor_arr(int count) {
	return new autor[count];
}

void InPut_Autor_arr(autor* A, int count)
{
	for (int i = 0;i < count;i++)
	{
		cout << "\nВведите фамилию автора: ";
		cin >> A[i].last_name;
		cout << "Введите гонорар этого автора: ";
		cin >> A[i].salary;
	}
}

void OutPut_Autor_arr(autor* A, int count) {
	for (int i = 0;i < count;i++)
	{
		cout << "\nФамилия " << i + 1 << "-го автора: " << A[i].last_name << ".";
		cout << "\nЕго гонорар: " << A[i].salary << "\n";
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