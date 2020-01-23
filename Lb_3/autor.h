#pragma once
#include "iostream"
using namespace std;

class autor
{
public:
	autor();
	autor(char*, char*, int = 20, int = 20);
	autor(const autor& A);
	~autor();

private:
	char* last_name;
	char* name;
	int s_last_name, s_name;

public:
	void Set_last_name(char*, int = 20);
	char* Get_last_name();

	void Set_name(char*, int = 20);
	char* Get_name();

};

