#include <bits/stdc++.h>
using namespace std;
struct lesson
{
    string lesson_name;
    int unit;
    float score;
};
struct student_info
{
    string name;
    string major;
    bool existance = false;
    int id;
    float gpa = 0;
    lesson lesson_list[100];
    void form();
};
void student_info::form()
{
    cout << "ENTER NAME : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "ENTER MAJOR : " << endl;
    getline(cin, major);
    cout << "ENTER ID : " << endl;
    cin >> id;
}
int findfreespace(student_info student[])
{
    for (int i = 0; i < 20; i++)
    {
        if (!student[i].existance)
            return i;
    }
    return -1;
}

int mainmenu()
{
    int choice;
    cout << "1. students" << endl
         << "2. show all students" << endl
         << "3. show students by major " << endl
         << "4. exit programm" << endl;
    cin >> choice;
    return choice;
}
int student_menu()
{
    int choice;
    cout << "1.add student" << endl
         << "2. remove student" << endl
         << "3. edit student" << endl
         << "4. show student report card" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    student_info student[20];
    int index;
lbl_menu:
    switch (mainmenu())
    {
    case 1:
    {
        switch (student_menu())
        {
        case 1:
        {
            index = findfreespace(student);
            student[index].form();
            goto lbl_menu;
            break;
        }
        }
    }
    }
}
