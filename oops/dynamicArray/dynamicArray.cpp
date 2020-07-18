#include <iostream>
#include "dynamicArray.h"

using namespace std;

DynamicArray::DynamicArray() {
    data = new int[5];
    capacity = 5;
    nextIndex = 0;
}

DynamicArray::DynamicArray(DynamicArray const &arr) {
    nextIndex = arr.nextIndex;
    capacity = arr.capacity;
    data = new int[capacity];

    for (int i = 0; i < nextIndex; i++) {
        data[i] = arr.data[i];
    }
}

void DynamicArray::operator=(DynamicArray const &arr) {
    nextIndex = arr.nextIndex;
    capacity = arr.capacity;
    data = new int[capacity];

    for (int i = 0; i < nextIndex; i++) {
        data[i] = arr.data[i];
    }
}

void DynamicArray::add(int element) {
    if (nextIndex == capacity) {
        int* newData = new int[capacity * 2];
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

void DynamicArray::add(int index, int element) {
    if (index < nextIndex) {
        data[index] = element;
    } else if (index == nextIndex) {
        DynamicArray::add(element);
    } else {
        return;
    }
}

void DynamicArray::print() const {
    for (int i = 0; i < nextIndex; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

int DynamicArray::get(int index) const {
    if (index >= 0 && index <= nextIndex) {
        return data[index];
    }

    return -1;
}