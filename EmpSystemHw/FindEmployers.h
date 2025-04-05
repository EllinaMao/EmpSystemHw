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

void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl);

void ShowEmployersGivenAge(EmployersArray& empls);
void ShowEmployersBySurnameLetter(EmployersArray& empls);


void SaveFoundedInfo(FoundedeEmp& empls);
