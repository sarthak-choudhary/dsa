#include <iostream>
#include <string>

using namespace std;

int minimum(int a, int b, int c) {
    int min = a;

    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    return min;
}

int editCount(string s1, string s2) {
    if (!s1.compare(s2)) {
        return 0;
    }

    if (s1.size() == 0 || s2.size() == 0) {
        if (s1.size() == 0) {
            return s2.size();
        } else {
            return s1.size();
        }
    }

    if (s1[0] == s2[0]) {
        return editCount(s1.substr(1), s2.substr(1));
    }

    int replace = editCount(s1.substr(1), s2.substr(1));
    int del = editCount(s1, s2.substr(1));
    int insert = editCount(s1.substr(1), s2);

    int min = minimum(replace, del, insert);

    return min + 1;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editCount(s1, s2) << endl;
}