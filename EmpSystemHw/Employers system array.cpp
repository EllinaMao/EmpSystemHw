#include "Employers system array.h"

void AddEmploye(EmployersArray& empls, EmployeTemp* /*empl*/)
{
    EmployeTemp* new_employer = new EmployeTemp;
    EnterEmploye(*new_employer); // func to allocate empl

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


void DeleteEmployeByIndex(EmployersArray& empls, int index)  
{  
   int new_count = empls.employers_count - 1;  
   EmployeTemp** temp = new EmployeTemp * [new_count];  

   for (int i = 0, j = 0; i < empls.employers_count; i++) {  
       if (i != index) {  
           temp[j++] = empls.all_empl[i];  
       }  
   }  

   delete empls.all_empl[index];  
   empls.employers_count--;  
   delete[] empls.all_empl;  
   empls.all_empl = temp;  
   temp = nullptr;  
}

void ShowAllEmployers(EmployersArray& empls)
{
    for (int i = 0; i < empls.employers_count; i++) {
        cout << i + 1 << ") ";
        ShowEmploye(*empls.all_empl[i]);
    }
}

void ShowEmployeByIndex(EmployersArray& empls, int index) {
    if (index >= empls.employers_count || index < 0 || !empls.all_empl) {
        return;
    }
    ShowEmploye(*empls.all_empl[index]);
}
void ChangeEmployeNameByIndex(EmployersArray& empls, EmployeTemp& empl, int index)
{
    if (index >= empls.employers_count || index < 0 || !empls.all_empl) {
        return;
    }

    cout << "Enter new name" << endl;
    EnterName(empl);

    delete[] empls.all_empl[index]->name;
    empls.all_empl[index]->name = new char[empl.namesize];
    strcpy_s(empls.all_empl[index]->name, empl.namesize, empl.name);  
    }

void ChangeEmployeSurnameByIndex(EmployersArray& empls, EmployeTemp& empl, int index)
{
    if (index >= empls.employers_count || index < 0 || !empls.all_empl) {
        return;
    }

    cout << "Enter new surname" << endl;
    EnterSurname(empl);

    delete[] empls.all_empl[index]->surname;
    empls.all_empl[index]->surname = new char[empl.surnamesize];
    strcpy_s(empls.all_empl[index]->surname, empl.surnamesize, empl.surname);
}

void ChangeEmployeAgeByIndex(EmployersArray& empls, EmployeTemp& empl, int index)  
{  
   if (index >= empls.employers_count || index < 0 || !empls.all_empl) {  
       return;  
   }  

   cout << "Enter new age" << endl;  
   EnterAge(empl);  

   empls.all_empl[index]->age = empl.age;  
}

void SaveInFile(EmployersArray& empls)
{
    FILE* outFile = fopen("employers.dat", "wb");

    if (!outFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    fwrite(&empls.employers_count, sizeof(int), 1, outFile);
    for (int i = 0; i < empls.employers_count; i++) {
        EmployeTemp* empl = empls.all_empl[i];
        fwrite(&empl->namesize, sizeof(int), 1, outFile);
        fwrite(empl->name, sizeof(char), empl->namesize, outFile);
        fwrite(&empl->surnamesize, sizeof(int), 1, outFile);
        fwrite(empl->surname, sizeof(char), empl->surnamesize, outFile);
        fwrite(&empl->age, sizeof(int), 1, outFile);
    }

    fclose(outFile);
}


void LoadFromFile(EmployersArray& empls)
{
    FILE* inFile = fopen("employers.dat", "rb");

    if (!inFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    fread(&empls.employers_count, sizeof(int), 1, inFile);
    EmployeTemp** temp_employers = new EmployeTemp * [empls.employers_count];

    for (int i = 0; i < empls.employers_count; i++) {
        EmployeTemp* new_employer = new EmployeTemp;

        fread(&new_employer->namesize, sizeof(int), 1, inFile);
        new_employer->name = new char[new_employer->namesize];
        fread(new_employer->name, sizeof(char), new_employer->namesize, inFile);

        fread(&new_employer->surnamesize, sizeof(int), 1, inFile);
        new_employer->surname = new char[new_employer->surnamesize];
        fread(new_employer->surname, sizeof(char), new_employer->surnamesize, inFile);

        fread(&new_employer->age, sizeof(int), 1, inFile);

        temp_employers[i] = new_employer;
    }

    delete[] empls.all_empl;
    empls.all_empl = temp_employers;

    fclose(inFile);
}
