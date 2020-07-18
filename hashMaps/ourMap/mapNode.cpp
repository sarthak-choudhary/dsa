#include <string>
#include <iostream>
#include "mapNode.h"

using namespace std;

template <typename V>
MapNode<V>::MapNode(string key, V value) {
    this -> key = key;
    this -> value = value;
    this -> next = NULL;
}

template <typename V>
MapNode<V>::~MapNode() {
    delete next;
}

template <typename V>
ourMap<V>::ourMap() {
    count = 0;
    numBuckets = 5;
    buckets = new MapNode<V>*[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }
}

template <typename V>
ourMap<V>::~ourMap() {
    for (int i = 0; i < numBuckets; i++) {
        delete buckets[i];
    }

    delete [] buckets;
}

template <typename V>
int ourMap<V>::size() {
    return count;
}

template <typename V>
int ourMap<V>::getBucketIndex(string key) {
    int hashCode {};

    int currentCoeff = 1;
    for (int i = key.length() - 1; i >= 0; i--) {
        hashCode += key[i] * currentCoeff;
        hashCode = hashCode % numBuckets;
        currentCoeff *= 37;
        currentCoeff = currentCoeff % numBuckets;
    }

    return hashCode % numBuckets;
}

template <typename V>
V ourMap<V>::getValue(string key) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];

    while (head != NULL) {
        if (head -> key == key) {
            return head -> value;
        }

        head = head -> next;
    }
    return 0;
}

template <typename V>
double ourMap<V>::getLoadFactor() {
    return (1.0 * count)/numBuckets;
}

template <typename V>
void ourMap<V>::rehash() {
    MapNode<V>** temp = buckets;
    buckets = new MapNode<V>*[2 * numBuckets];
    for (int i = 0; i < 2*numBuckets; i++) {
        buckets[i] = NULL;
    }

    int oldBucketCount = numBuckets;
    numBuckets *= 2;
    count = 0;

    for (int i = 0; i < oldBucketCount; i++) {
        MapNode<V>* head = temp[i];

        while(head != NULL) {
            string key = head -> key;
            V value = head -> value;
            insert(key, value);
            head = head -> next;
        }
    }

    for (int i = 0; i < oldBucketCount; i++) {
        MapNode<V>* head = temp[i];
        delete head;
    }

    delete [] temp;
}

template <typename V>
void ourMap<V>::insert(string key, V value) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while (head != NULL) {
        if (head -> key == key) {
            head -> value = value;
            return;
        }
        head = head -> next;
    }

    MapNode<V>* node = new MapNode<V>(key, value);
    node -> next = head;
    buckets[bucketIndex] = node;
    count++;
    double loadFactor = (1.0 * count)/numBuckets;
    if (loadFactor > 0.7) {
        rehash();
    }
}

template <typename V>
V ourMap<V>::remove(string key) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    MapNode<V>* prev = NULL;
    while (head != NULL) {
        if (head -> key == key) {
            if (prev == NULL) {
                buckets[bucketIndex] = head -> next;
            } else {
                prev->next = head->next;
            }
            V value = head -> value;
            head -> next = NULL;
            delete head;
            count--;
            return value;
        }
        prev = head;
        head = head -> next;
    }
    return 0;    
}