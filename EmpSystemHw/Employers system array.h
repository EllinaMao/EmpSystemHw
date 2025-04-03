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
Напишите информационную систему "Сотрудники". Программа должна обеспечивать ввод данных,
редактирование данных сотрудника, удаление сотрудника, поиск сотрудника по фамилии, вывод информации
обо всех сотрудниках, указанного возраста, или фамилия которых начинается на указанную букву.
Организуйте возможность сохранения найденной информации в файл.
Также весь список сотрудников сохраняется в файл (при выходе из программы – автоматически,
в процессе исполнения программы – по команде пользователя).
При старте программы происходит загрузка списка сотрудников из указанного пользователем файла.
*/
