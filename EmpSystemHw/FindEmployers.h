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
	int employers_count = 0;
};

void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp&fe);

void ShowEmployersGivenAge(EmployersArray& empls, FoundedeEmp& fe);
void ShowEmployersBySurnameLetter(EmployersArray& empls, FoundedeEmp& fe);


void SaveFoundedInfo(FoundedeEmp& empls);
