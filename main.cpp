#include <bits/stdc++.h>
#include <limits>
#include <iomanip>
using namespace std;

class Student
{
public:
    int rollNumber;
    string fullName;
    int year;
    string branch;
    float cgpa;
};

const int MAX_STUDENTS = 100;

Student students[MAX_STUDENTS];
int studentCount = 0;

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void addStudent()
{
    if (studentCount == MAX_STUDENTS)
    {
        cout << "\nMaximum student limit reached!\n";
        return;
    }

    cout << "\n========== Add New Student ==========\n\n";

    cout << "Enter Roll Number : ";
    cin >> students[studentCount].rollNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNumber == students[studentCount].rollNumber)
        {
            cout << "\nRoll Number already exists!\n";
            pauseScreen();
            return;
        }
    }

    cout << "Enter Full Name   : ";
    getline(cin, students[studentCount].fullName);

    cout << "Enter Branch      : ";
    getline(cin, students[studentCount].branch);

    do
    {
        cout << "Enter Year (1-4) : ";
        cin >> students[studentCount].year;

        if (students[studentCount].year < 1 ||
            students[studentCount].year > 4)
        {
            cout << "Invalid year! Please enter between 1 and 4.\n";
        }

    } while (students[studentCount].year < 1 ||
             students[studentCount].year > 4);

    do
    {
        cout << "Enter CGPA : ";
        cin >> students[studentCount].cgpa;

        if (students[studentCount].cgpa < 0 ||
            students[studentCount].cgpa > 10)
        {
            cout << "Invalid CGPA! Please enter between 0 and 10.\n";
        }

    } while (students[studentCount].cgpa < 0 ||
             students[studentCount].cgpa > 10);

    studentCount++;

    cout << "\nStudent added successfully!\n";

    // cout << "\nPress Enter to continue...";
    pauseScreen();
}

void displayStudents()
{
    cout << "\n========== Student List ==========\n";

    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        pauseScreen();
        return;
    }

    cout << "\nTotal Students : " << studentCount << "\n\n";

    cout << left
         << setw(10) << "Roll"
         << setw(25) << "Name"
         << setw(40) << "Branch"
         << setw(10) << "Year"
         << setw(10) << "CGPA" << endl;

    cout << string(90, '-') << endl;

    for (int i = 0; i < studentCount; i++)
    {
        cout << left
             << setw(10) << students[i].rollNumber
             << setw(25) << students[i].fullName
             << setw(40) << students[i].branch
             << setw(10) << students[i].year
             << setw(10) << fixed << setprecision(2) << students[i].cgpa
             << endl;
    }

    pauseScreen();
}

void searchStudent()
{

    int searchRoll;
    cout << "\nEnter Roll Number to Search : ";
    cin >> searchRoll;
    // bool found = false;
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";

        // cout << "\nPress Enter to continue...";
        pauseScreen();
        return;
    }
    bool found = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (searchRoll == students[i].rollNumber)
        {
            cout << "\n========== Student Found ==========\n";
            cout << endl;
            cout << "Roll Number : " << students[i].rollNumber << endl;
            cout << "Full Name   : " << students[i].fullName << endl;
            cout << "Branch      : " << students[i].branch << endl;
            cout << "Year        : " << students[i].year << endl;
            cout << "CGPA        : " << fixed << setprecision(2)
                 << students[i].cgpa << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nStudent not found!\n";
    }

    pauseScreen();
}

void updateStudent()
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        pauseScreen();
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to Update : ";
    cin >> roll;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNumber == roll)
        {
            found = true;

            cout << "\nCurrent Details\n";
            cout << "------------------------\n";
            cout << "Roll Number : " << students[i].rollNumber << endl;
            cout << "Full Name   : " << students[i].fullName << endl;
            cout << "Branch      : " << students[i].branch << endl;
            cout << "Year        : " << students[i].year << endl;
            cout << "CGPA        : " << fixed << setprecision(2)
                 << students[i].cgpa << endl;

            cout << "\nEnter New Full Name : ";
            getline(cin, students[i].fullName);

            cout << "Enter New Branch : ";
            getline(cin, students[i].branch);

            do
            {
                cout << "Enter New Year (1-4): ";
                cin >> students[i].year;

                if (students[i].year < 1 || students[i].year > 4)
                    cout << "Invalid Year!\n";

            } while (students[i].year < 1 || students[i].year > 4);

            do
            {
                cout << "Enter New CGPA : ";
                cin >> students[i].cgpa;

                if (students[i].cgpa < 0 || students[i].cgpa > 10)
                    cout << "Invalid CGPA!\n";

            } while (students[i].cgpa < 0 || students[i].cgpa > 10);

            cout << "\nStudent Updated Successfully!\n";

            pauseScreen();
            return;
        }
    }

    if (!found)
        cout << "\nStudent not found!\n";

    pauseScreen();
}
void deleteStudent()
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        pauseScreen();
        return;
    }

    int roll;

    cout << "\nEnter Roll Number to Delete : ";
    cin >> roll;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNumber == roll)
        {
            found = true;

            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;

            cout << "\nStudent Deleted Successfully!\n";
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!\n";

    pauseScreen();
}
void showMenu()
{
    cout << "\n========================================\n";
    cout << "   COLLEGE STUDENT MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
}

int main()
{
    int choice;

    while (true)
    {
        showMenu();

        cout << "----------------------------------------\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank you for using College Student Management System!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}