#include "menu.h"


void Menu()
{
	cout << R"(
1. Show Employers
2. Add Employer
3. Remove Employer
4. Search Employer by surname
5. Change Employer by id
6. Display Employers Count
7. Save Data
8. Load Data
0. Exit
)" << endl;
}

void MenuChange()
{
	cout << R"(
1. Change Employer name
2. Change Employer surname
3. Change Employer age
)" << endl;
}

void MenuShow()
{
cout << R"(
1. Show all Employers
2. Show Employers by exact age
3. Show Employers whose surname starts with a specific letter
)" << endl;
}

/*
Напишите информационную систему "Сотрудники". Программа должна обеспечивать ввод данных,
редактирование данных сотрудника, удаление сотрудника, поиск сотрудника по фамилии, вывод информации
обо всех сотрудниках, указанного возраста, или фамилия которых начинается на указанную букву.
Организуйте возможность сохранения найденной информации в файл.
Также весь список сотрудников сохраняется в файл (при выходе из программы – автоматически,
в процессе исполнения программы – по команде пользователя).
При старте программы происходит загрузка списка сотрудников из указанного пользователем файла.

поиск сотрудника по фамилии, вывод информации
обо всех сотрудниках, указанного возраста, или фамилия которых начинается на указанную букву.
Организуйте возможность сохранения найденной информации в файл.
*/