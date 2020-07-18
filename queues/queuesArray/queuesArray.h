#ifndef _QUEUESARRAY_H_
#define _QUEUESARRAY_H_

template <typename T>

class QueuesUsingArray {
    T *data;
    int nextIndex;
    int firstIndex;
    int queueSize;
    int capacity;

    public : 

    QueuesUsingArray(int totalSize = 5);
    QueuesUsingArray(QueuesUsingArray<T> const &queue);
    int size();
    bool isEmpty();
    void enqueue(T element);
    T dequeue();
    T front();

};


#endif