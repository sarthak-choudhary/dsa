#include <iostream>
#include "Student.h"

using namespace std;

void display_student(Student s) {
    s.name[0] = 'x';
    s.display();
}

int main() {
    Student s1;
    Student s2 {"student2", 20};
    Student s3 {"student3", 20, 112};

    s1.display();
    s2.display();
    s3.display();
    display_student(s3);

    s3.display();

}