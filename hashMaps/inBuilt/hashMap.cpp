#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> ourMap;

    //insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;
    ourMap["abc"] = 3;

    //find or access
    //if you try to access using [] brackets , even if the key is not present it will create one and assign it to zero.

    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    //ourMap.at("ghi") will throw an error
    //ourMap["ghi"] will create a key with value 0

    cout << "size: " << ourMap.size() << endl;
    cout << ourMap["ghi"] << endl;
    cout << "size: " << ourMap.size() << endl;
 
    //check presence
    if (ourMap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    //erase
    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    cout << "size: " << ourMap.size() << endl;

    return 0;

}