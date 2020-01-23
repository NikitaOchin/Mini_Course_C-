#pragma once
#include "iostream"
#include "Book.h"
#include "autor.h"
#include "assert.h"

class Book_In_library :
	public Book
{
public:
	Book_In_library();
	Book_In_library(int n, bool a, char* N, double c, int s_n = 20);
	Book_In_library(int n, bool a, char* N, double c, char* t, char* U, autor& A, int s_t = 20, int s_U = 20, int s_n = 20);
	Book_In_library(const Book_In_library& B);
	~Book_In_library();

private:
	int number;
	bool availability;
	char* Name;
	int s_name;
	double cost;

public:
	void Set_number(int);
	const int Get_number();

	void Set_availability(bool);
	const bool Get_availability();

	void Set_Name(char*, int s_name = 20);
	const char* Get_Name();

	void Set_cost(double);
	const double Get_cost();

	void OutPutLib();

};

