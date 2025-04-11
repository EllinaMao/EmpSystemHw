#include "menu.h"


void EnterMenu()
{
	cout << R"(
1. Create frest employers sistem file
2. Load file
)" << endl;
}

void Menu()
{
	cout << R"(
1. Show Employers
2. Add Employer
3. Remove Employer
4. Search Employer by surname
5. Change Employer by index
6. Display Employers Count
7. Save Data
0. Exit
)" << endl;
}

void MenuChange()
{
	cout << R"(
1. Change Employer name
2. Change Employer surname
3. Change Employer age
0. Return to the menu
)" << endl;
}

void MenuShow()
{
cout << R"(
1. Show all Employers
2. Show Employers by exact age
3. Show Employers whose surname starts with a specific letter
0. Return to the menu
)" << endl;
}

int GetNumber()
{
	int num = 0;
	cout << "Enter your choice: ";
	cin >> num;
	cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return num;
}

void MenuFound()
{	cout << R"(
You want to save in txt file?
1. Yes
2. No
)" << endl;
}