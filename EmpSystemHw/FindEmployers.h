#pragma once
#include "Employers.h"
#include "Employers system array.h"

/*
����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
*/

struct FoundedeEmp {
	EmployeTemp** all_empl = nullptr;
	int* emp_id = nullptr;
	int employers_count = 0;
};

void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp&fe);

void ShowEmployersGivenAge(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp& fe);
void ShowEmployersBySurnameLetter(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp& fe);

char InputLetter();

void SaveFoundedInfo(FoundedeEmp& empls);

void DeleteFoundedEmp(FoundedeEmp& fe);
void ShowFoundedEmpl(FoundedeEmp& fe);