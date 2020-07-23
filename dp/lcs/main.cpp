#include <iostream>
#include <string>

using namespace std;

int maximum(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    return max;
}

int subsequence(string first, string second) {
    if (first.size() == 0 || second.size() == 0) {
        return 0;
    }

    if (first[0] == second[0]) {
        return subsequence(first.substr(1), second.substr(1)) + 1;
    }

    int a = subsequence(first.substr(1), second);
    int b = subsequence(first, second.substr(1));
    int c = subsequence(first.substr(1), second.substr(1));

    return maximum(a, b, c);
}

int main() {
    string first = "sarthak";
    string second = "akhtahk";

    cout << first << endl;
    cout << second << endl;

    cout << subsequence(first, second) << endl;
}