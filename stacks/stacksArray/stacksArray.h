#ifndef _STACKSARRAY_H_
#define _DYNAMICARRAY_H_

template <typename T>

class StackUsingArray {
    T *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray();
    StackUsingArray(StackUsingArray<T> const &stack);
    int size();
    bool isEmpty();
    void push(T element);
    T pop();
    T top();
};

#endif