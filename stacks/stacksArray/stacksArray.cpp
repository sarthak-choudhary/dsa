#include <iostream>
#include "stacksArray.h"

using namespace std;

template <typename T>
StackUsingArray<T>::StackUsingArray()
    :nextIndex {0}, capacity {4} {
        data = new T[4];
}

template <typename T>
StackUsingArray<T>::StackUsingArray(StackUsingArray const &stack) 
    :nextIndex {stack.nextIndex}, capacity {stack.capacity} {
        data = new T[capacity];

        for(int i = 0; i < capacity; i++) {
            data[i] = stack.data[i];
        }
}

template <typename T>
int StackUsingArray<T>::size() {
    return nextIndex;
}

template <typename T>
bool StackUsingArray<T>::isEmpty() {
    return nextIndex == 0;
}

template <typename T>
void StackUsingArray<T>::push(T element) {
    if (nextIndex == capacity) {
        cout << "stack capacity is being double" << endl;
        T *newData = new T[capacity * 2];

        for (int i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }

        delete [] data;
        data = newData;

        capacity = capacity * 2;
    }

    data[nextIndex] = element;
    nextIndex++;
}

template <typename T>
T StackUsingArray<T>::pop() {
    if (nextIndex == 0) {
        cout << "stack is empty" << endl;
        return 0;
    } 

    nextIndex--;
    return data[nextIndex];
}

template <typename T>
T StackUsingArray<T>::top() {
    if (nextIndex == 0) {
        cout << "stack is empty" << endl;
        return 0;
    }

    return data[nextIndex - 1];
}
