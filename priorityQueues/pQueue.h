#ifndef _PQUEUE_H_
#define _PQUEUE_H_
#include <vector>

using namespace std;

class PriorityQueue {
    vector<int> pq;

    public:
    bool isEmpty();
    int getSize();
    int getMin();
    void insert(int data);
    int removeMin();
};

#endif