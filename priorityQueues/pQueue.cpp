#include "pQueue.h"
using namespace std;

bool PriorityQueue::isEmpty() {
    return pq.size() == 0;
}

int PriorityQueue::getSize() {
    return pq.size();
}

int PriorityQueue::getMin() {
    if (pq.size() == 0) {
        return 0;  //indicator that the heap is empty
    }

    return pq[0];
}

void PriorityQueue::insert(int data) {
    pq.push_back(data);

    int childIndex = pq.size() - 1;
    while (childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if (pq[childIndex] < pq[parentIndex]) {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
        } else {
            break;
        }

        childIndex = parentIndex;
    }
}

int PriorityQueue::removeMin() {
    if (pq.size() ==  0) {
        return 0;
    }

    int answer = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();
    int size = pq.size();

    if (size == 0) {
        return answer;
    }

    int parentIndex {};
    int leftChildIndex = (2 * parentIndex) + 1;
    int rightChildIndex = (2 * parentIndex) + 2;

    while (leftChildIndex < size || rightChildIndex < size) {
        if (rightChildIndex < size) {
            if (min(pq[parentIndex], min(pq[leftChildIndex], pq[rightChildIndex])) != pq[parentIndex]) {
                int minIndex {};
                if (pq[leftChildIndex] < pq[rightChildIndex]) {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[leftChildIndex];
                    pq[leftChildIndex] = temp;
                    minIndex = leftChildIndex;
                } else {
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[rightChildIndex];
                    pq[rightChildIndex] = temp;
                    minIndex = rightChildIndex;
                }

                parentIndex = minIndex;
                leftChildIndex = (2 * parentIndex) + 1;
                rightChildIndex = (2 * parentIndex) + 2;
            } else {
                return answer;
            }
        } else {
            if (min(pq[leftChildIndex], pq[parentIndex]) != pq[parentIndex]) {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[leftChildIndex];
                pq[leftChildIndex] = temp;
            }

            return answer;
        }
    }

    return answer;
}

