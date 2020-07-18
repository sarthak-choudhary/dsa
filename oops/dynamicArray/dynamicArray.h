#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

class DynamicArray {
    int* data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray();
    DynamicArray(DynamicArray const &arr);
    void operator=(DynamicArray const &arr);
    void add(int element);
    void add(int index, int element);
    void print() const;
    int get(int index) const;
};

#endif