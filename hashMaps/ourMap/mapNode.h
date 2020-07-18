#ifndef _MAPNODE_H_
#define _MAPNODE_H_

#include <string>
using namespace std;

template <typename V>
class MapNode {
    public:
    string key;
    V value;
    MapNode<V>* next;

    MapNode(string key, V value);
    ~MapNode();
};

template <typename V>
class ourMap {
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    int getBucketIndex(string key);

    public:
    ourMap();
    ~ourMap();
    int size();
    V getValue(string key);
    void insert(string key, V value);
    V remove(string key);
    void rehash();
    double getLoadFactor();
};

#endif