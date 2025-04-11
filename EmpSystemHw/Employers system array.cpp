#include "Employers system array.h"

void AddEmploye(EmployersArray& empls)
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
    int size = strlen(empl.name) + 1;
    empls.all_empl[index]->name = new char[size];
    strcpy_s(empls.all_empl[index]->name, size, empl.name);
    }

void ChangeEmployeSurnameByIndex(EmployersArray& empls, EmployeTemp& empl, int index)
{
    if (index >= empls.employers_count || index < 0 || !empls.all_empl) {
        return;
    }

    cout << "Enter new surname" << endl;
    EnterSurname(empl);

    delete[] empls.all_empl[index]->surname;
    int size = strlen(empl.surname) + 1;
    empls.all_empl[index]->surname = new char[size];
    strcpy_s(empls.all_empl[index]->surname, size, empl.surname);
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
    FILE* outFile = nullptr;
    fopen_s(&outFile, empls.filename, "wb");
    size_t name_length = 0;
    size_t surname_length = 0;
    if (!outFile) {
        cout << "File could not be opened!" << endl;
        return;
    }

    fwrite(&empls.employers_count, sizeof(int), 1, outFile);
    for (int i = 0; i < empls.employers_count; i++) {
        EmployeTemp* empl = empls.all_empl[i];

        // Write name
        name_length = strlen(empl->name) + 1;
        fwrite(&name_length, sizeof(int), 1, outFile); // Save name length
        fwrite(empl->name, sizeof(char), name_length, outFile);

        // Write surname
        surname_length = strlen(empl->surname) + 1;
        fwrite(&surname_length, sizeof(int), 1, outFile); // Save surname length
        fwrite(empl->surname, sizeof(char), surname_length, outFile);

        // Write age
        fwrite(&empl->age, sizeof(int), 1, outFile);
    }

    fclose(outFile);
}


void LoadFromFile(EmployersArray& empls)
{
    FILE* inFile = nullptr;
    fopen_s(&inFile, empls.filename, "rb");

    if (!inFile) {
        cout << "File could not be opened! Program will start empty." << endl;
        return;
    }

    // Read the number of employers
    fread(&empls.employers_count, sizeof(int), 1, inFile);
    if (empls.employers_count <= 0) {
        cout << "Invalid employers count in file! Program will start empty." << endl;
        fclose(inFile);
        return;
    }

    // Allocate memory for employers
    EmployeTemp** temp_employers = new EmployeTemp * [empls.employers_count];

    for (int i = 0; i < empls.employers_count; i++) {
        EmployeTemp* new_employer = new EmployeTemp;

        // Read name
        int name_length = 0;
        fread(&name_length, sizeof(int), 1, inFile);
        if (name_length <= 0) {
            cout << "Invalid name length in file!" << endl;
            delete new_employer;
            continue;
        }
        new_employer->name = new char[name_length];
        fread(new_employer->name, sizeof(char), name_length, inFile);

        // Read surname
        int surname_length = 0;
        fread(&surname_length, sizeof(int), 1, inFile);
        if (surname_length <= 0) {
            cout << "Invalid surname length in file!" << endl;
            delete[] new_employer->name;
            delete new_employer;
            continue;
        }
        new_employer->surname = new char[surname_length];
        fread(new_employer->surname, sizeof(char), surname_length, inFile);

        // Read age
        fread(&new_employer->age, sizeof(int), 1, inFile);

        temp_employers[i] = new_employer;
    }

    // Clean up old data and assign new data
    delete[] empls.all_empl;
    empls.all_empl = temp_employers;

    fclose(inFile);
    return;
}

void EnterFilename(EmployersArray& empls)
{
    short tempsize = 50;
    char* temp = new char[tempsize];

    cin.getline(temp, tempsize);
    if (cin.fail()) { cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

    int size = strlen(temp) + 1;
    empls.filename = new char[size];
    strcpy_s(empls.filename, size, temp);
    delete[] temp;
}

void SetTestFilename(EmployersArray& empls)
{
    const char* default_filename = "employers.dat";  
    size_t length = (strlen(default_filename) + 1);
    empls.filename = new char[length];  
    strcpy_s(empls.filename, length, default_filename);  
}

EmployersArray::~EmployersArray()
{
    for (int i = 0; i < employers_count; ++i) {
        delete all_empl[i];
    }
    delete[] all_empl;

    delete[] filename;
}
