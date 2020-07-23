#include <iostream>
#include <string>

using namespace std;

//Question: make two strings equal by upadating, deleting, or inserting a character in one of the string
//          count each of the above steps as 1, return the min. Total steps to make them same
//input:    string1
//          string2
//output:   (int) number of steps

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

int helper(int** answers, string s1, string s2) {
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

    for(int i = 0; i <= s2.size(); i++) {
        for(int j = 0; j <= s1.size(); j++) {
            if (i == 0 || j == 0) {
                answers[i][j] = i + j;
                continue;
            }

            if (s2[s2.size() - i] == s1[s1.size() - j]) {
                answers[i][j] = answers[i - 1][j - 1];
            } else {
                int replace = answers[i - 1][j - 1] + 1;
                int del = answers[i][j - 1] + 1;
                int insert = answers[i - 1][j] + 1;

                int min = minimum(replace, del, insert);

                answers[i][j] = min;
            }
        }
    }

    return answers[s2.size()][s1.size()];
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    int** answers = new int*[s2.size() + 1];
    for (int i = 0; i <= s2.size(); i++) {
        answers[i] = new int[s1.size() + 1];
    }

    cout << helper(answers, s1, s2) << endl;
}
