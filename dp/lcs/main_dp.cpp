#include <iostream>
#include <string>

using namespace std;

//Question: find length of longest common subsequence of two given strings.
//input : string1
//        string2

//output : (int) length of required subsequence.
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

int subsequence(int** answers, string first, string second) {
    for (int i = 0; i <= second.size(); i++) {
        for (int j = 0; j <= first.size(); j++) {
            if (i == 0 || j == 0) {
                answers[i][j] = 0;
                continue;
            }
            if (first[first.size() - j] == second[second.size() - i]) {
                answers[i][j] = answers[i - 1][j - 1] + 1;
            } else {
                int a = answers[i][j - 1];
                int b = answers[i - 1][j];
                int c = answers[i - 1][j - 1];

                int max = maximum(a, b, c);
                answers[i][j] = max;
            } 
        }
    }

    return answers[second.size()][first.size()];
}

int main() {
    string first;
    string second;

    cin >> first;
    cin >> second; 

    int** answers = new int*[second.size() + 1];

    for (int i = 0; i <= second.size(); i++) {
        answers[i] = new int[first.size() + 1];
    }

    cout << subsequence(answers, first, second) << endl;

}