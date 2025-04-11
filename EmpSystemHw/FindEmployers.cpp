#include "FindEmployers.h"

void FindEmployeSurname(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp& fe)
{
    DeleteFoundedEmp(fe);

    int match_count = 0;
    for (int i = 0; i < empls.employers_count; ++i) {
        if (strcmp(empls.all_empl[i]->surname, empl.surname) == 0) {
            ++match_count;
        }
    }

    if (match_count == 0) {
        cout << "No employees found with the surname: " << empl.surname << endl;
        return;
    }

    fe.all_empl = new EmployeTemp * [match_count];
    fe.emp_id = new int[match_count];
    fe.employers_count = match_count;

    // Store matching employees
    int index = 0;
    for (int i = 0; i < empls.employers_count; ++i) {
        if (strcmp(empls.all_empl[i]->surname, empl.surname) == 0) {
            fe.all_empl[index] = empls.all_empl[i];
            fe.emp_id[index] = i;
            ++index;
        }
    }

    cout << "Found " << fe.employers_count << " employee(s) with the surname: " << empl.surname << endl;
    ShowFoundedEmpl(fe);
}

void ShowEmployersGivenAge(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp& fe)  
{ 
   DeleteFoundedEmp(fe);  

   int match_count = 0;  
   for (int i = 0; i < empls.employers_count; ++i) {  
       if (empls.all_empl[i]->age == empl.age) {  
           ++match_count;  
       }  
   }  

   if (match_count == 0) {  
       cout << "No employees found with the age: " << empl.age << endl;  
       return;  
   }  

   fe.all_empl = new EmployeTemp * [match_count];  
   fe.emp_id = new int[match_count];  
   fe.employers_count = match_count;  

   // Store matching employees  
   int index = 0;  
   for (int i = 0; i < empls.employers_count; ++i) {  
       if (empls.all_empl[i]->age == empl.age) {  
           fe.all_empl[index] = empls.all_empl[i];  
           fe.emp_id[index] = i;  
           ++index;  
       }  
   }  

   cout << "Found " << fe.employers_count << " employee(s) with the age: " << empl.age << endl;  
   ShowFoundedEmpl(fe);  
}

void ShowEmployersBySurnameLetter(EmployersArray& empls, EmployeTemp& empl, FoundedeEmp& fe)  
{  
   DeleteFoundedEmp(fe);  

   char letter = InputLetter();  
   int match_count = 0;  

   for (int i = 0; i < empls.employers_count; ++i) {  
       if (empls.all_empl[i]->surname[0] == letter) {  
           ++match_count;  
       }  
   }  

   if (match_count == 0) {  
       cout << "No employees found with surnames starting with the letter: " << letter << endl;  
       return;  
   }  

   fe.all_empl = new EmployeTemp * [match_count];  
   fe.emp_id = new int[match_count];  
   fe.employers_count = match_count;  

   int index = 0;  
   for (int i = 0; i < empls.employers_count; ++i) {  
       if (empls.all_empl[i]->surname[0] == letter) {  
           fe.all_empl[index] = empls.all_empl[i];  
           fe.emp_id[index] = i;  
           ++index;  
       }  
   }  

   cout << "Found " << fe.employers_count << " employee(s) with surnames starting with the letter: " << letter << endl;  
   ShowFoundedEmpl(fe);  
}

char InputLetter()
{
    cout << "Enter letter" << endl;
    char letter = _getch();
    letter = toupper(letter);
    cout << letter << endl;


    return letter;
}

void SaveFoundedInfo(FoundedeEmp& empls)  
{  
   if (empls.employers_count == 0 || empls.emp_id == nullptr || empls.all_empl == nullptr) {  
       cout << "No data to save." << endl;  
       return;  
   }  


   FILE* file = nullptr;
   fopen_s(&file, "founded_employees.txt", "w");  

   if (!file) {  
       cout << "Error: Unable to open file for saving." << endl;  
       return;  
   }  

   for (int i = 0; i < empls.employers_count; ++i) {  
       fprintf(file, "Employee ID: %d\n", empls.emp_id[i]);  
       fprintf(file, "Name: %s\n", empls.all_empl[i]->name);  
       fprintf(file, "Surname: %s\n", empls.all_empl[i]->surname);  
       fprintf(file, "Age: %d\n\n", empls.all_empl[i]->age);  
   }  

   fclose(file);  
   cout << "Employee information saved to 'founded_employees.txt'." << endl;  
}


void ShowFoundedEmpl(FoundedeEmp& fe) {
    if (fe.employers_count, fe.emp_id, fe.all_empl) {
        for (int i = 0; i < fe.employers_count; ++i) {
            cout << "Employee ID: " << fe.emp_id[i] << endl;
            ShowEmploye(*fe.all_empl[i]);
        }
    }
}
void DeleteFoundedEmp(FoundedeEmp& fe)
{
    if (fe.all_empl) {
        fe.all_empl = nullptr;
    }
    if (fe.emp_id) {
    fe.emp_id = nullptr;
    }
    fe.employers_count = 0;
}
