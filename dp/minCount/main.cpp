#include <iostream>

using namespace std;

int helper(int* answers, int n) {
    answers[0] = 0;
    answers[1] = 1;
    answers[2] = 2;

    for(int i = 3; i <= n; i++) {
        int count = -1;
        int num = 1;
        while (i - (num * num) >= 0) {
            if (count ==  -1 || answers[i - (num * num)] + 1 < count) {
                count = answers[i - (num * num)] + 1;
            }

            num++;
        }

        answers[i] = count;
    }

    return answers[n];
}

int minCount(int n) {
    int* answers = new int[n+1];
    return helper(answers, n);
}

int main() {
    cout << minCount(17) << endl;
}