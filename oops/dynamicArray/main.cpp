#include <iostream>
#include "dynamicArray.h"

using namespace std;

int main() {
    DynamicArray d1;

    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    cout << "d1 first time" << endl;
    d1.print();
    DynamicArray d2 {d1};
    d1.add(0, 100);
    cout << "d2 with first element as zero" << endl;
    d2.print();

    cout << "d1 after changing fisrt element to 100" << endl;
    d1.print();

    DynamicArray d3 = d1;
    d1.add(0, 1000);
    cout << "d3 with first element 100" << endl;
    d3.print();

    cout << "d1 after changing first element to 1000" << endl;
    d1.print();   
}