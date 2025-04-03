#pragma once
#include "Employers.h"
#include "Employers system array.h"

/*
поиск сотрудника по фамилии, вывод информации
обо всех сотрудниках, указанного возраста, или фамилия которых начинается на указанную букву.
Организуйте возможность сохранения найденной информации в файл.
*/

struct EmployeSavesArr{
	char* savefile;
	char** saveallfiles;
};


void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl);

void ShowEmployersGivenAge(EmployersArray& empls);
void ShowEmployersBySurnameLetter(EmployersArray& empls);


void SaveFoundedInfo(EmployersArray& empls);
