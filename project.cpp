#include <bits/stdc++.h>
using namespace std;
void getvalidint(auto &x)
{
    while (1)
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT! PLEASE TRY AGAIN" << endl;
        }
        else
        {
            break;
        }
    }
}
struct lesson
{
    string lesson_name;
    int unit;
    float score;
    bool existance = false;
};
struct student_info
{
    string name;
    string major;
    bool existance = false;
    int id;
    float gpa = 0;
    int unitsum = 0;
    void form();
    void GPA();
    lesson lesson_list[100];
    void report_card();
    void makeprofile();
    void add_lesson();
    void read_lesson(int);
};
void student_info::form()
{
    cout << "ENTER NAME : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "ENTER MAJOR : " << endl;
    getline(cin, major);
    cout << "ENTER ID : " << endl;
    getvalidint(id);
    if (existance == false)
    {
        add_lesson();
    }
    GPA();
    existance = true;
}
void student_info::GPA()
{
    int unitsum = 0;
    gpa = 0;
    for (int i = 0; i < 100; i++)
    {
        if (lesson_list[i].existance == false)
            continue;
        unitsum += lesson_list[i].unit;
        gpa += lesson_list[i].unit * lesson_list[i].score;
    }
    gpa /= unitsum;
}
void student_info::read_lesson(int i)
{
    float x;
    cout << "ENTER LESSON NAME : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, lesson_list[i].lesson_name);
    cout << "ENTER UNITS : ";
    getvalidint(lesson_list[i].unit);
    cout << "ENTER SCORE : ";
    getvalidint(x);
    lesson_list[i].score = x;
    lesson_list[i].existance = true;
}
void student_info::report_card()
{
    if (!existance)
    {
        cout << "NO MATCH STUDENT!" << endl;
        return;
    }

    cout << "\n=====================================" << endl;
    cout << "             REPORT CARD             " << endl;
    cout << "=====================================" << endl;

    cout << "NAME   : " << name << endl;
    cout << "MAJOR  : " << major << endl;
    cout << "ID     : " << id << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    cout << left << setw(20) << " LESSON"
         << setw(10) << "| UNITS"
         << setw(10) << "| SCORE" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    for (int i = 0; i < 100; i++)
    {
        if (lesson_list[i].existance)
        {
            cout << left << setw(20) << lesson_list[i].lesson_name << "|"
                 << setw(10) << lesson_list[i].unit << "|"
                 << setw(9) << fixed << setprecision(2) << lesson_list[i].score << endl;
        }
    }
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    cout << "STUDENT GPA : " << fixed << setprecision(2) << gpa << endl;
    cout << "=====================================" << endl
         << endl;
}
void student_info::makeprofile()
{
    form();
    existance = true;
}
int mainmenu()
{
    cout << "======================================" << endl;
    cout << "           MAIN MENU                " << endl;
    cout << "======================================" << endl;
    int choice;
    cout << "1. students" << endl
         << "2. show all students" << endl
         << "3. show students by major " << endl
         << "4. exit programm" << endl;
    getvalidint(choice);
    return choice;
}
int student_menu()
{
    cout << "======================================" << endl;
    cout << "           STUDENT MENU                " << endl;
    cout << "======================================" << endl;
    int choice;
    cout << "1.add student" << endl
         << "2. remove student" << endl
         << "3. edit student" << endl
         << "4. show student report card" << endl;
    getvalidint(choice);
    return choice;
}
int edit_studentmenu()
{
    cout << "======================================" << endl;
    cout << "           EDIT STUDENT               " << endl;
    cout << "======================================" << endl;
    int choice;
    cout << "1. edit student personal info" << endl
         << "2. edit lessons" << endl;
    getvalidint(choice);
    return choice;
}
int lesson_menu()
{
    cout << "======================================" << endl;
    cout << "           LESSON MENU                " << endl;
    cout << "======================================" << endl;
    int choice;
    cout << "1. add lesson" << endl
         << "2. remove lesson" << endl
         << "3. edit lesson" << endl;
    getvalidint(choice);
    return choice;
}
void sortby_GPA(student_info student[])
{
    int i, j;
    student_info temp;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20 - i - 1; j++)
        {
            if (student[j].gpa < student[j + 1].gpa)
            {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}
int search_student(student_info student[], int id)
{
    for (int i = 0; i < 20; i++)
        if (student[i].id == id)
        {
            return i;
        }
    return -1;
}
void editprofile(int index, student_info student[])
{
    student[index].form();
}
int search_lesson(string search, student_info student[], int i)
{
    for (int j = 0; j < 100; j++)
    {
        if (search == student[i].lesson_list[j].lesson_name)
        {
            return j;
        }
    }
    return -1;
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
void student_info::add_lesson()
{
    int choice;
    for (int i = 0; i < 100; i++)
    {
        if (lesson_list[i].existance == true)
            continue;
        cout << "1. ADD LESSON " << endl
             << "2.EXIT" << endl;
        getvalidint(choice);
        if (choice == 2)
        {
            break;
        }
        else if (choice != 1)
        {
            cout << "invalid please try again";
            continue;
        }
        read_lesson(i);
    }
    GPA();
}
void show_allstudent(student_info student[])
{
    sortby_GPA(student);
    cout << left << setw(6) << "RANK" << setw(30) << "| NAME" << setw(20) << "| MAJOR" << setw(15) << "| ID" << setw(5) << "| GPA" << endl;
    cout << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
    int j = 1;
    for (int i = 0; i < 20; i++)
    {
        if (student[i].existance == true)
        {
            cout << left << setw(6) << j << '|' << setw(29) << student[i].name << '|' << setw(19) << student[i].major << '|' << setw(14) << student[i].id << '|' << setw(5) << student[i].gpa << endl;
            j++;
            cout << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
        }
    }
}
void show_studentbymajor(student_info student[])
{
    string major;
    cout << "ENTER MAJOR : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, major);
    sortby_GPA(student);
    cout << left << setw(6) << "RANK" << setw(30) << "| NAME" << setw(20) << "| MAJOR" << setw(15) << "| ID" << setw(5) << "| GPA" << endl;
    cout << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
    int j = 1;
    for (int i = 0; i < 20; i++)
    {
        if (student[i].existance == true && student[i].major == major)
        {
            cout << left << setw(6) << j << '|' << setw(29) << student[i].name << '|' << setw(19) << student[i].major << '|' << setw(14) << student[i].id << '|' << setw(5) << student[i].gpa << endl;
            j++;
            cout << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
        }
    }
}
int main()
{
    student_info student[20];
    int index;
lbl_mainmenu:
    switch (mainmenu())
    {
    case 1:
    {
        switch (student_menu())
        {
        case 1:
        {
            index = findfreespace(student);
            if (index == -1)
            {
                cout << "NO SPACE FOR NEW STUDENT!" << endl;
                goto lbl_mainmenu;
            }
            student[index].form();
            goto lbl_mainmenu;
            break;
        }
        case 2:
        {
            int id;
            cout << "ENTER SEARCH ID : " << endl;
            getvalidint(id);
            if (search_student(student, id) == -1)
            {
                cout << "NO MATCH STUDENT!" << endl;
                goto lbl_mainmenu;
            }
            student[search_student(student, id)].existance = false;
            goto lbl_mainmenu;
            break;
        }
        case 3:
        {
            switch (edit_studentmenu())
            {
            case 1:
            {
                int id;
                cout << "ENTER STUDENT ID : ";
                getvalidint(id);
                if (search_student(student, id) == -1)
                {
                    cout << "NO MATCH STUDENT!" << endl;
                    goto lbl_mainmenu;
                }
                student[search_student(student, id)].form();
                goto lbl_mainmenu;
                break;}
            case 2:
            {
                switch (lesson_menu())
                {
                case 1:
                {
                    int id;
                    cout << "ENTER STUDENT ID : ";
                    getvalidint(id);
                    if (search_student(student, id) == -1)
                    {
                        cout << "NO MATCH STUDENT!" << endl;
                        goto lbl_mainmenu;
                    }
                    student[search_student(student, id)].add_lesson();
                    goto lbl_mainmenu;
                    break;
                }
                case 2:
                {
                    int id;
                    cout << "ENTER STUDENT ID : " << endl;
                    getvalidint(id);
                    if (search_student(student, id) == -1)
                    {
                        cout << "NO MATCH STUDENT!" << endl;
                        goto lbl_mainmenu;
                    }
                    string name;
                    cout << "ENTER LESSON NAME : " << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, name);
                    if (search_lesson(name, student, search_student(student, id)) == -1)
                    {
                        cout << "NO MATCH LESSON!" << endl;
                        goto lbl_mainmenu;
                    }
                    student[search_student(student, id)].lesson_list[search_lesson(name, student, search_student(student, id))].existance = false;
                    student[search_student(student, id)].GPA();
                    goto lbl_mainmenu;
                    break;
                }
                case 3:
                {
                    int id;
                    cout << "ENTER STUDENT ID : " << endl;
                    getvalidint(id);
                    string name;
                    cout << "ENTER LESSON NAME YOU WANT TO EDIT : " << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, name);
                    if (search_lesson(name, student, search_student(student, id)) == -1)
                    {
                        cout << "NO MATCH LESSON!" << endl;
                        goto lbl_mainmenu;
                    }
                    student[search_student(student, id)].read_lesson(search_lesson(name, student, search_student(student, id)));
                    goto lbl_mainmenu;
                    break;
                }
                            default:
                cout << "INVALID OPTION!, TRY AGAIN"<<endl;
                goto lbl_mainmenu;
                }
            }
                        default:
                cout << "INVALID OPTION!, TRY AGAIN"<<endl;
                goto lbl_mainmenu;
            }
        }
        case 4:
        {
            int id;
            cout << "ENTER STUDENT ID :" << endl;
            getvalidint(id);
            if (search_student(student, id) == -1)
            {
                cout << "NO MATCH STUDENT!" << endl;
                goto lbl_mainmenu;
            }
            student[search_student(student, id)].report_card();
            goto lbl_mainmenu;
            break;
        }
        default:
            cout << "INVALID OPTION!, TRY AGAIN"<<endl;
        }
    }

    case 2:
    {
        show_allstudent(student);
        goto lbl_mainmenu;
        break;
    }
    case 3:
    {
        show_studentbymajor(student);
        goto lbl_mainmenu;
        break;
    }
    case 4:
    {
        return 0;
    }
    default:
        cout << "INVALID OPTION!, TRY AGAIN"<<endl;
        goto lbl_mainmenu;
    }
}
