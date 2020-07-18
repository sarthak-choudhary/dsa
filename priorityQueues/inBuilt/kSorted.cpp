#include <iostream>
#include <queue>

using namespace std;

int main() {
    int input[] = {10, 12, 6, 7, 9};
    int n = 5;
    int k = 3;
    priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        pq.push(input[i]);
    }

    int j {};
    for (int i = k; i < n; i++) {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;        
    }

    for (int i = 0; i < k; i++) {
        input[j] = pq.top();
        pq.pop();
        j++;
    }

    for (int i = 0; i < n; i++) {
        cout << input[i] << endl;
    }
}