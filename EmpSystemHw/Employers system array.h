#pragma once
#include "Employers.h"


struct EmployersArray {  
   EmployeTemp** all_empl = nullptr;  
   int employers_count = 0;  
   char* filename = nullptr;  

   ~EmployersArray();
};


void AddEmploye(EmployersArray& empls);
void DeleteEmployeByIndex(EmployersArray& empls, int index);
void ShowAllEmployers(EmployersArray& empls);
void ShowEmployeByIndex(EmployersArray& empls, int index);

void ChangeEmployeNameByIndex(EmployersArray& empls, EmployeTemp& empl, int index);
void ChangeEmployeSurnameByIndex(EmployersArray& empls, EmployeTemp& empl, int index);
void ChangeEmployeAgeByIndex(EmployersArray& empls, EmployeTemp& empl, int index);


void SaveInFile(EmployersArray& empls);
void LoadFromFile(EmployersArray& empls);

void EnterFilename(EmployersArray& empls);
void SetTestFilename(EmployersArray& empls);



/*
�������� �������������� ������� "����������". ��������� ������ ������������ ���� ������,
�������������� ������ ����������, �������� ����������, ����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
����� ���� ������ ����������� ����������� � ���� (��� ������ �� ��������� � �������������,
� �������� ���������� ��������� � �� ������� ������������).
��� ������ ��������� ���������� �������� ������ ����������� �� ���������� ������������� �����.
*/
