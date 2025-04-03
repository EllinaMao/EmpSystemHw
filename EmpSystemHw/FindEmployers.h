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

void ShowEmployersGivenAge(EmployersArray& empls);
void ShowEmployersBySurnameLetter(EmployersArray& empls);


void SaveFoundedInfo(EmployersArray& empls);
