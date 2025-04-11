#include <iostream>  
#include <conio.h>  
#include "Employers.h"  
#include "Employers system array.h"
#include "FindEmployers.h"
#include "menu.h"
using namespace std;  
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

int main()
{
    cout << "Welcome to the Employers System!" << endl;
    EnterMenu();
    int task = 0;
    int index = 0;
    EmployeTemp empl;
    EmployersArray emplarr;
    FoundedeEmp fe;

    task = GetNumber();

    while (true) {
        if (task == 1) {
            cout << "Enter new file name" << endl;
            EnterFilename(emplarr);
            break;
        }

        else if (task == 2) {
            cout << "Enter your file name" << endl;
            EnterFilename(emplarr);
            //SetTestFilename(emplarr);//for tests
            LoadFromFile(emplarr);
            break;
        }
        else{
            cout << "Wrong operation, try again" << endl;
        }
    }


    while (true) {

        Menu();
        task = GetNumber();

        if (task == 1) //1. Show Employers
        {
            MenuShow();
            task = GetNumber();
            
            if (task == 1) //Show all Employers
            {
                cout << "Displaying all employers: " << endl;
                ShowAllEmployers(emplarr);
            }
            else if (task == 2)//Show Employers by exact age
            {
                cout << "Displaying employers by exact age: " << endl;
                EnterAge(empl);
                ShowEmployersGivenAge(emplarr, empl, fe);

                MenuFound();
                task = GetNumber();
                if (task == 1) {
                    SaveFoundedInfo(fe);
                }
                else { cout << "Returning to the menu" << endl; }
            }
            else if (task == 3) //Show Employers whose surname starts with a specific letter
            {
                cout << "Displaying employers whose surname starts with a specific letter: " << endl;
                ShowEmployersBySurnameLetter(emplarr, empl, fe);

                MenuFound();
                task = GetNumber();
                if (task == 1) {
                    SaveFoundedInfo(fe);
                }
                else { cout << "Returning to the menu" << endl; }
            }
            else if (task == 0) { continue; }
            else { cout << "Incorrect operation, retuning to the menu." << endl; }

            
        }

        else if (task == 2) //Add Employer
        {
            cout << "Adding employer" << endl;
            AddEmploye(emplarr);
        }
        else if (task == 3) //Remove Employer
        {
            cout << "Please enter index of employer what you want to remove: " << endl;
            index = GetNumber();
            DeleteEmployeByIndex(emplarr, index);
        }
        else if (task == 4) //Search Employer by surname
        {
            cout << "Enter surname: " << endl;
            EnterSurname(empl);
            FindEmployeSurname(emplarr, empl, fe);
        }
        else if (task == 5) //Change Employer by index
        {
            MenuChange();
            task = GetNumber();
            cout << "Please enter index of employer what you want to change: " << endl;
            index = GetNumber();
            if (task == 1) // Change Employer name
            {
                ChangeEmployeNameByIndex(emplarr, empl, index);
            }
            else if (task == 2)//Change Employer surname
            {
                ChangeEmployeSurnameByIndex(emplarr, empl, index);
            }
            else if (task == 3) //Change Employer age
            {
                ChangeEmployeAgeByIndex(emplarr, empl, index);
            }
            else if (task == 0) { continue; }
            else { cout << "Incorrect operation, retuning to the menu." << endl; }
        }
        else if (task == 6) //Display Employers Count
        {
            cout<<"Employers count: " << emplarr.employers_count << endl;
        }
        else if (task == 7) //Save Data
        {
            SaveInFile(emplarr);
        }
        else if (task == 0) //exit
        {
            cout << "Exit program and saving data." << endl;
            SaveInFile(emplarr);
            break;
        }
        else { cout << "Incorrect operation. Try again." << endl; }
    }
    return 0;
}
