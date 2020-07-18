#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {

public:
    char *name;
    int age;
    int rollNumber;


    void display();
    Student(char *name = "student", int age = 18, int rollNumber = 100);
    Student(Student const &s);
    ~Student();
};

#endif