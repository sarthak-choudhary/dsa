#include <iostream>
#include <queue>

using namespace std;

int main() {
    // by default the priority queue is max priority queue
    priority_queue<int> pq; //to add elements in priority queue
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;

    // syntax for min priority queue
    priority_queue<int, vector<int>, greater<int>> min_pq;

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }    
}