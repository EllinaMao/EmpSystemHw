#pragma once
#include "Employers.h"
#include "Employers system array.h"

/*
����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
*/

struct EmployeSavesArr{
	char* savefile;
	char** saveallfiles;
};


void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl);

void ShowAllEmployers(EmployersArray& empls);
void ShowEmployersGivenAge(EmployersArray& empls);
void ShowEmployersBySurnameLetter(EmployersArray& empls);


void SaveFoundedInfo(EmployersArray& empls);
