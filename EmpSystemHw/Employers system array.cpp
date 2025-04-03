#include "Employers system array.h"

void AddEmploye(EmployersArray& empls, EmployeTemp* empl)
{
	EmployeTemp* new_employer = new EmployeTemp;
	EnterEmploye(*new_employer);

	int new_count = empls.employers_count + 1;

	EmployeTemp** temp = new EmployeTemp * [new_count];

	for (int i = 0; i < empls.employers_count; i++) {
		temp[i] = empls.all_empl[i];
	}

	temp[new_count - 1] = new_employer;
	empls.employers_count++;
	delete[] empls.all_empl;
	empls.all_empl = temp;
	temp = nullptr;
	new_employer = nullptr;
}
