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
};
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
int main()
{
}
