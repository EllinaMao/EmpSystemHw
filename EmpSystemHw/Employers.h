#pragma once
#include <iostream>
#include <conio.h>
using namespace std;



struct EmployeTemp {

	int age;
	int namesize = 0;
	int surnamesize = 0;
	char* surname;
	char* name;
};


void EnterEmploye(EmployeTemp& et);

void EnterName(EmployeTemp& et);
void EnterSurname(EmployeTemp& et);
void EnterAge(EmployeTemp& et);

void ShowEmploye(EmployeTemp& et);
