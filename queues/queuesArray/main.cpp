#include <iostream>
#include "queuesArray.cpp"

using namespace std;

int main() {
    QueuesUsingArray<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;

    cout << q1.size() << endl;
    cout << q1.isEmpty() << endl;

    
}