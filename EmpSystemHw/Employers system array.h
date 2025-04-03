#pragma once
#include "Employers.h"


struct EmployersArray {
	EmployeTemp** all_empl = nullptr;
	int employers_count = 0;
};


void AddEmploye(EmployersArray& empls, EmployeTemp* empl);
void DeleteEmployeByIndex(EmployersArray& empls, int index);
void ShowAllEmployers(EmployersArray& empls);
void ShowEmployeByIndex(EmployersArray& empls, int index);

void ChangeEmployeNameByIndex(EmployersArray& empls, EmployeTemp& empl, int index);
void ChangeEmployeSurnameByIndex(EmployersArray& empls, EmployeTemp& empl, int index);
void ChangeEmployeAgeByIndex(EmployersArray& empls, EmployeTemp& empl, int index);


void SaveInFile(EmployersArray& empls);
void LoadFromFile(EmployersArray& empls);






/*
�������� �������������� ������� "����������". ��������� ������ ������������ ���� ������,
�������������� ������ ����������, �������� ����������, ����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
����� ���� ������ ����������� ����������� � ���� (��� ������ �� ��������� � �������������,
� �������� ���������� ��������� � �� ������� ������������).
��� ������ ��������� ���������� �������� ������ ����������� �� ���������� ������������� �����.
*/
