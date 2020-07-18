#include <iostream>
#include <string>
#include "mapNode.cpp"

using namespace std;

int main() {
    ourMap<int> map;
    
    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        map.insert(key, i);
        cout << key << " inserted " << map.getLoadFactor() << endl;
    }

    cout << map.size() << endl;
    map.remove("abc3");
    map.remove("abc1");
    cout << map.size() << endl;

    for (int i = 0; i < 10; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << ": " << map.getValue(key) << endl;
    }

    cout << map.size() << endl;

}