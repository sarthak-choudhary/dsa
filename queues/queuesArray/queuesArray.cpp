#include <iostream>
#include <string>
#include "queuesArray.h"

using namespace std;

template <typename T>
QueuesUsingArray<T>::QueuesUsingArray(int totalSize)
    :firstIndex {-1}, nextIndex {0}, queueSize {0}, capacity {totalSize} {
        data = new T[capacity];
}

template <typename T>
QueuesUsingArray<T>::QueuesUsingArray(QueuesUsingArray<T> const &queue)
    :firstIndex {queue.firstIndex}, capacity {queue.capacity}, nextIndex {queue.nextIndex}, queueSize {queue.queueSize} {
        data = new T[capacity];

        for(int i = 0; i < capacity; i++) {
            data[i] = queue.data[i];
        }
}

template <typename T>
int QueuesUsingArray<T>::size() {
    return queueSize;
}

template <typename T>
bool QueuesUsingArray<T>::isEmpty() {
    return queueSize == 0;
}

template <typename T>
void QueuesUsingArray<T>::enqueue(T element) {
    if (firstIndex == -1) {
        data[0] = element;
        firstIndex++;
        nextIndex++;
        queueSize++;

        return;
    }

    if (nextIndex % capacity == firstIndex % capacity) {
        cout << "Queue is Being doubled" << endl;
        
        T* newData = new T[capacity * 2];
        int fi = firstIndex;

        for (int i = 0; i < capacity; i++) {
            newData[i] = data[fi % capacity];
            fi++;
        }

        delete [] data;
        data = newData;

        firstIndex = 0;
        nextIndex = capacity;
        capacity = capacity * 2;
        // cout << "Queue is full ! Sorry can't add more" << endl;
        // return;
    }

    nextIndex = nextIndex % capacity;
    data[nextIndex] = element;
    queueSize++;
    nextIndex++;

    return;
}

template <typename T>
T QueuesUsingArray<T>::dequeue() {
    if (firstIndex == -1 || firstIndex == nextIndex) {
        cout << "Queue is empty nothing to dequeue" << endl;
        return 0;
    }

    firstIndex = firstIndex % capacity;
    T extra = data[firstIndex];
    firstIndex++;

    queueSize--;

    if (queueSize == 0) {
        nextIndex = 0;
        firstIndex = -1;
    }

    return extra;
}

template <typename T>
T QueuesUsingArray<T>::front() {
    if (firstIndex == -1 || firstIndex == nextIndex) {
        cout << "Queue is empty nothing in front" << endl;
        return 0;
    }

    return data[firstIndex % capacity];
}
