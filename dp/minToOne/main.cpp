#include <iostream>

using namespace std;

int minStepsHelper(int* answers, int n) {
    if (n == 1) {
        return 0;
    }

    int a = -1;
    int b = -1;
    int c = -1;
    int min;

    if (answers[n - 1] == -1) {
        answers[n - 1] = minStepsHelper(answers, n - 1);
    }

    c = answers[n - 1];
    min = c;

    if (n % 2 == 0) {
        answers[n/2] = minStepsHelper(answers, n/2);
        b = answers[n/2];
    }

    if (b != -1 && b < min) {
        min = b;
    }

    if (n % 3 == 0) {
        answers[n/3] = minStepsHelper(answers, n/3);
        c = answers[n/3];
    }

    if (c != -1 && c < min) {
        min = c;
    }

    return min + 1;
}

int minStepsToOne(int n) {
    int* answers = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        answers[i] = -1;
    }

    return minStepsHelper(answers, n);
}

int main() {
    cout << minStepsToOne(245) << endl;
}