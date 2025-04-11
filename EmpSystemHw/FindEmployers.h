#pragma once
#include "Employers.h"
#include "Employers system array.h"

/*
поиск сотрудника по фамилии, вывод информации
обо всех сотрудниках, указанного возраста, или фамилия которых начинается на указанную букву.
Организуйте возможность сохранения найденной информации в файл.
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