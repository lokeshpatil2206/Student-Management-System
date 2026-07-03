#include<bits/stdc++.h>
using namespace std;
void addStudent()
{
    cout << "-----Add New Student-----" << endl;
    
}
int main(){
    int choice;

while(true)
{
    cin >> choice;

    if(choice == 1)
    {
        addStudent();
    }
    else if(choice == 2)
    {
        displayStudents();
    }
    else if(choice == 3)
    {
        break;
    }
}
}