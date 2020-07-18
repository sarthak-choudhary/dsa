#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

void Student::display() {
    cout << name << " " << age << " " << rollNumber << endl;
}

Student::Student(char *name, int age, int rollNumber)
    : name {nullptr},age {age}, rollNumber {rollNumber} {
        char *studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        this -> name = studentName;
    }

Student::~Student() {
    delete name;
}

Student::Student(Student const &s) {
    char *studentName = new char[strlen(s.name) + 1];
    strcpy(studentName, s.name);
    name = studentName;
    age = s.age;
    rollNumber = s.rollNumber;
}
