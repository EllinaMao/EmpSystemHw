#include "Employers.h"

void EnterEmploye(EmployeTemp& et)
{

	cout << "Enter name" << endl;
	EnterName(et);
	cout << "Enter surname" << endl;
	EnterSurname(et);
	cout << "Enter age" << endl;
	EnterAge(et);

}

void EnterName(EmployeTemp& et)
{
	if (et.name) {
		delete[] et.name;
		et.name = nullptr;
	}

	short tempsize = 50;
	char* temp = new char[tempsize];

	cin.getline(temp, tempsize);
	if (cin.fail()) { cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

	if (temp[0] != '\0') {
		temp[0] = toupper(temp[0]);
	}
	for (int i = 1; temp[i] != '\0'; ++i) {
		temp[i] = tolower(temp[i]);
	}

	int size = strlen(temp) + 1;
	et.name = new char[size];
	strcpy_s(et.name, size, temp);
	delete[] temp;
}

void EnterSurname(EmployeTemp& et)
{
	if (et.surname) {
		delete[] et.surname;
		et.surname = nullptr;
	}

	short tempsize = 50;
	char* temp = new char[tempsize];

	cin.getline(temp, tempsize);
	if (cin.fail()) { cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

	if (temp[0] != '\0') {
		temp[0] = toupper(temp[0]);
	}
	for (int i = 1; temp[i] != '\0'; ++i) {
		temp[i] = tolower(temp[i]);
	}

	int size = strlen(temp) + 1;
	et.surname = new char[size];
	strcpy_s(et.surname, size,temp);
	delete[] temp;
}

void EnterAge(EmployeTemp& et)
{
	cin >> et.age;
	if (cin.fail()) { cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
}

void ShowEmploye(EmployeTemp& et)
{
	cout << "Name: " <<et.name<< endl;
	cout << "Surname: " << et.surname << endl;
	cout << "Age: " << et.age << endl;

}
