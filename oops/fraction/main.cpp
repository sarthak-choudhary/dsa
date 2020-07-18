#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    Fraction f1(10, 2);
    Fraction f2(10, 35);
    const Fraction f3(19, 27);
    f1.print();
    Fraction f4 = f1;
    (f4 += f1) += f2;

    f1.print();
    f4.print();
    // f2.print();
    // f3.print();
    // f4.print();

    // f4 = f1 + f2;
    // cout << "After adding f1 + f2 = f4." << endl;
    // f4.print();

    // Fraction f5 = f1 * f2;
    // Fraction f6 = f5;
    // cout << "After multiplying f1 * f2 = f5." << endl;
    // f5.print();

    // if (f5 == f1) {
    //     cout << "Things went wrong" << endl;
    // } else {
    //     cout << "Showing that f1 and f5 are not equal" << endl;
    // }

    // if (f5 == f6) {
    //     cout << "Showing that f5 and f6 are equal" << endl;
    // }

}