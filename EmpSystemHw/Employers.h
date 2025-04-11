#pragma once
#include <iostream>
#include <conio.h>
using namespace std;



struct EmployeTemp {

	int age = 0;
	char* surname = nullptr;
	char* name = nullptr;
};


void EnterEmploye(EmployeTemp& et);

void EnterName(EmployeTemp& et);
void EnterSurname(EmployeTemp& et);
void EnterAge(EmployeTemp& et);

void ShowEmploye(EmployeTemp& et);
