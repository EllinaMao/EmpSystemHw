#include <iostream>  
#include <conio.h>  
#include "Employers.h"  
#include "Employers system array.h"
#include "menu.h"
using namespace std;  
/*
�������� �������������� ������� "����������". ��������� ������ ������������ ���� ������,
�������������� ������ ����������, �������� ����������, ����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
����� ���� ������ ����������� ����������� � ���� (��� ������ �� ��������� � �������������,
� �������� ���������� ��������� � �� ������� ������������).
��� ������ ��������� ���������� �������� ������ ����������� �� ���������� ������������� �����.

����� ���������� �� �������, ����� ����������
��� ���� �����������, ���������� ��������, ��� ������� ������� ���������� �� ��������� �����.
����������� ����������� ���������� ��������� ���������� � ����.
*/

int main()  
{  
    char inFile[] = "employers_data.txt";  
    FILE* empsys = nullptr;
    cout << "Welcome to the Employer System" << endl;  
    int task = 0;
    EmployeTemp empl;
    EmployersArray emplarr;
    while (true){

        Menu();
        cout << "Enter your choice: ";
        cin >> task;


        if (task == 1) {
        }
        else if (task == 1) {
        }
        else if (task == 2) {
        }
        else if (task == 3) {
        }
        else if (task == 4) {
        }
        else if (task == 5) {
        }
        else if (task == 6) {
        }
        else if (task == 7) {
        }
        else if (task == 8) {
        }
        else if (task == 0) {
            cout << "Exit program and saving data" << endl;
            SaveInFile(emplarr);
            break;
        }
        else {
            cout << "Try again" << endl;
        }

  return 0;  
}
