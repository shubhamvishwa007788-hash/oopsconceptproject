#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


class Person
{
protected:
    string name;
    int age;
    string gender;

public:

    Person()
    {
        name = "";
        age = 0;
        gender = "";
    }

    Person(string n, int a, string g)
    {
        name = n;
        age = a;
        gender = g;
    }

    void setPerson(string n, int a, string g)
    {
        name = n;
        age = a;
        gender = g;
    }

    string getName()
    {
        return name;
    }

    virtual void display()
    {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Gender : " << gender << endl;
    }

    virtual ~Person() {}
};


/* =========================================================
   HIERARCHICAL INHERITANCE

                 Person
                /      \
           Student     Teacher
   ========================================================= */

class Student : public Person
{
protected:
    int rollNo;
    string course;
    int semester;

public:

    Student() : Person()
    {
        rollNo = 0;
        course = "";
        semester = 0;
    }

    void setStudent(
        string n,
        int a,
        string g,
        int r,
        string c,
        int s)
    {
        setPerson(n, a, g);

        rollNo = r;
        course = c;
        semester = s;
    }

    int getRollNo()
    {
        return rollNo;
    }

    string getCourse()
    {
        return course;
    }

    virtual void display()
    {
        Person::display();

        cout << "Roll No : " << rollNo << endl;
        cout << "Course  : " << course << endl;
        cout << "Semester: " << semester << endl;
    }
};


/* =========================================================
   TEACHER CLASS
   HIERARCHICAL INHERITANCE
   ========================================================= */

class Teacher : public Person
{
private:
    int employeeId;
    string subject;
    double salary;

public:

    Teacher()
    {
        employeeId = 0;
        subject = "";
        salary = 0;
    }

    void setTeacher(
        string n,
        int a,
        string g,
        int id,
        string sub,
        double sal)
    {
        setPerson(n, a, g);

        employeeId = id;
        subject = sub;
        salary = sal;
    }

    void display()
    {
        cout << "\n========== TEACHER DETAILS ==========\n";

        Person::display();

        cout << "Employee ID : " << employeeId << endl;
        cout << "Subject     : " << subject << endl;
        cout << "Salary      : Rs. " << salary << endl;
    }
};


/* =========================================================
   MULTILEVEL INHERITANCE

   Person
      |
   Student
      |
   BCAStudent
   ========================================================= */

class BCAStudent : public Student
{
protected:
    string programmingLanguage;
    string specialization;

public:

    BCAStudent() : Student()
    {
        programmingLanguage = "";
        specialization = "";
    }

    void setBCA(
        string n,
        int a,
        string g,
        int r,
        string c,
        int s,
        string language,
        string spec)
    {
        setStudent(n, a, g, r, c, s);

        programmingLanguage = language;
        specialization = spec;
    }

    void display()
    {
        cout << "\n========== BCA STUDENT ==========\n";

        Student::display();

        cout << "Programming Language : "
             << programmingLanguage << endl;

        cout << "Specialization       : "
             << specialization << endl;
    }
};


/* =========================================================
   CLASS FOR MULTIPLE INHERITANCE
   ========================================================= */

class Academic
{
protected:
    float marks;
    float attendance;

public:

    Academic()
    {
        marks = 0;
        attendance = 0;
    }

    void setAcademic(float m, float a)
    {
        marks = m;
        attendance = a;
    }

    void academicDetails()
    {
        cout << "\n========== ACADEMIC DETAILS ==========\n";

        cout << "Marks      : " << marks << "%" << endl;
        cout << "Attendance : " << attendance << "%" << endl;

        if (marks >= 80)
        {
            cout << "Grade      : A+" << endl;
        }
        else if (marks >= 70)
        {
            cout << "Grade      : A" << endl;
        }
        else if (marks >= 60)
        {
            cout << "Grade      : B" << endl;
        }
        else if (marks >= 50)
        {
            cout << "Grade      : C" << endl;
        }
        else
        {
            cout << "Grade      : F" << endl;
        }
    }
};


/* =========================================================
   SPORTS CLASS
   ========================================================= */

class Sports
{
protected:
    string sportName;
    string achievement;

public:

    Sports()
    {
        sportName = "";
        achievement = "";
    }

    void setSports(string sport, string achieve)
    {
        sportName = sport;
        achievement = achieve;
    }

    void sportsDetails()
    {
        cout << "\n========== SPORTS DETAILS ==========\n";

        cout << "Sport       : " << sportName << endl;
        cout << "Achievement : " << achievement << endl;
    }
};


/* =========================================================
   MULTIPLE + MULTILEVEL INHERITANCE

   BCAStudent + Academic + Sports
             |
       StudentProfile

   ========================================================= */

class StudentProfile :
    public BCAStudent,
    public Academic,
    public Sports
{
private:
    double fees;
    string email;

public:

    StudentProfile() : BCAStudent()
    {
        fees = 0;
        email = "";
    }

    void setProfile(
        string n,
        int a,
        string g,
        int r,
        string c,
        int s,
        string language,
        string spec,
        float m,
        float att,
        string sport,
        string achieve,
        double f,
        string e)
    {
        setBCA(
            n,
            a,
            g,
            r,
            c,
            s,
            language,
            spec
        );

        setAcademic(m, att);

        setSports(
            sport,
            achieve
        );

        fees = f;
        email = e;
    }

    void display()
    {
        cout << "\n";
        cout << "============================================\n";
        cout << "          COMPLETE STUDENT PROFILE\n";
        cout << "============================================\n";

        BCAStudent::display();

        cout << "Email    : " << email << endl;
        cout << "Fees     : Rs. " << fees << endl;

        academicDetails();

        sportsDetails();

        cout << "============================================\n";
    }

    void saveToFile()
    {
        ofstream file("students.txt", ios::app);

        if (!file)
        {
            cout << "File could not be opened!\n";
            return;
        }

        file << "Roll No: " << rollNo << endl;
        file << "Name: " << name << endl;
        file << "Course: " << course << endl;
        file << "Semester: " << semester << endl;
        file << "Email: " << email << endl;
        file << "Marks: " << marks << endl;
        file << "Attendance: " << attendance << endl;
        file << "Sport: " << sportName << endl;
        file << "Fees: " << fees << endl;

        file << "----------------------------------\n";

        file.close();

        cout << "\nStudent data saved successfully!\n";
    }
};


/* =========================================================
   HYBRID INHERITANCE

   Person
   /    \
Student Teacher
   |
BCAStudent
   |
StudentProfile
   /       \
Academic   Sports

Multiple inheritance + Multilevel + Hierarchical
========================================================= */


/* =========================================================
   ADD STUDENT FUNCTION
   ========================================================= */

StudentProfile createStudent()
{
    StudentProfile student;

    string name;
    int age;
    string gender;

    int roll;
    string course;
    int semester;

    string language;
    string specialization;

    float marks;
    float attendance;

    string sport;
    string achievement;

    double fees;
    string email;


    cout << "\n========== ADD NEW STUDENT ==========\n";

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Roll Number: ";
    cin >> roll;

    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, course);

    cout << "Enter Semester: ";
    cin >> semester;

    cin.ignore();

    cout << "Enter Programming Language: ";
    getline(cin, language);

    cout << "Enter Specialization: ";
    getline(cin, specialization);

    cout << "Enter Marks (%): ";
    cin >> marks;

    cout << "Enter Attendance (%): ";
    cin >> attendance;

    cin.ignore();

    cout << "Enter Sport Name: ";
    getline(cin, sport);

    cout << "Enter Achievement: ";
    getline(cin, achievement);

    cout << "Enter Fees: ";
    cin >> fees;

    cin.ignore();

    cout << "Enter Email: ";
    getline(cin, email);


    student.setProfile(
        name,
        age,
        gender,
        roll,
        course,
        semester,
        language,
        specialization,
        marks,
        attendance,
        sport,
        achievement,
        fees,
        email
    );

    return student;
}


/* =========================================================
   SEARCH STUDENT
   ========================================================= */

void searchStudent(
    vector<StudentProfile>& students)
{
    if (students.empty())
    {
        cout << "\nNo student records available.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    bool found = false;

    for (auto& student : students)
    {
        if (student.getRollNo() == roll)
        {
            student.display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent not found!\n";
    }
}


/* =========================================================
   DISPLAY ALL STUDENTS
   ========================================================= */

void displayAll(
    vector<StudentProfile>& students)
{
    if (students.empty())
    {
        cout << "\nNo students available.\n";
        return;
    }

    cout << "\n\n";
    cout << "============================================\n";
    cout << "              ALL STUDENTS\n";
    cout << "============================================\n";

    for (auto& student : students)
    {
        student.display();
    }
}


/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main()
{
    vector<StudentProfile> students;

    vector<Teacher> teachers;


    int choice;

    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       COLLEGE MANAGEMENT SYSTEM\n";
        cout << "============================================\n";

        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Add Teacher\n";
        cout << "5. Display Teachers\n";
        cout << "6. Exit\n";

        cout << "============================================\n";

        cout << "Enter Your Choice: ";
        cin >> choice;


        switch (choice)
        {

        /* -----------------------------------------
           ADD STUDENT
           ----------------------------------------- */

        case 1:
        {
            StudentProfile student =
                createStudent();

            students.push_back(student);

            student.saveToFile();

            cout << "\nStudent added successfully!\n";

            break;
        }


        /* -----------------------------------------
           DISPLAY ALL STUDENTS
           ----------------------------------------- */

        case 2:
        {
            displayAll(students);

            break;
        }


        /* -----------------------------------------
           SEARCH STUDENT
           ----------------------------------------- */

        case 3:
        {
            searchStudent(students);

            break;
        }


        /* -----------------------------------------
           ADD TEACHER
           ----------------------------------------- */

        case 4:
        {
            Teacher teacher;

            string name;
            int age;
            string gender;

            int id;
            string subject;
            double salary;

            cin.ignore();

            cout << "\n========== ADD TEACHER ==========\n";

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter Gender: ";
            getline(cin, gender);

            cout << "Enter Employee ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Subject: ";
            getline(cin, subject);

            cout << "Enter Salary: ";
            cin >> salary;

            teacher.setTeacher(
                name,
                age,
                gender,
                id,
                subject,
                salary
            );

            teachers.push_back(teacher);

            cout << "\nTeacher added successfully!\n";

            break;
        }


        /* -----------------------------------------
           DISPLAY TEACHERS
           ----------------------------------------- */

        case 5:
        {
            if (teachers.empty())
            {
                cout << "\nNo teacher records available.\n";
            }
            else
            {
                for (auto& teacher : teachers)
                {
                    teacher.display();
                }
            }

            break;
        }

        case 6:
        {
            cout << "\nThank you for using College Management System!\n";

            break;
        }


        default:
        {
            cout << "\nInvalid choice! Please try again.\n";
        }

        }

    }
    while (choice != 6);


    return 0;
}