#pragma once
#include "Employers.h"


struct EmployersArray {
	EmployeTemp* all_empl;
};


void AddEmploye(EmployersArray& empls, EmployeTemp& empl);
void DeleteEmploye(EmployersArray& empls);
void ChangeEmployeName(EmployersArray& empls, EmployeTemp& empl);
void ChangeEmployeSurname(EmployersArray& empls, EmployeTemp& empl);
void ChangeEmployeAge(EmployersArray& empls, EmployeTemp& empl);


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
