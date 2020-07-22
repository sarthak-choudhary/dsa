#include <iostream>

using namespace std;

int fibo(int n) {
    if (n <= 1) {
        return n;
    }

    int a = fibo(n- 1);
    int b = fibo(n -2);

    return a + b;
}
int fibo_3(int n) {
    int* ans = new int[n + 1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i- 1] + ans[i - 2];
    }

    return ans[n];
}

int fibo_helper(int* answers, int n) {
    if (n <= 1) {
        return n;
    }

    if (answers[n] != -1) {
        return answers[n];
    }

    int a = fibo_helper(answers, n - 1);
    int b = fibo_helper(answers, n - 2);

    answers[n] = a + b;
    return a + b;
}

int fibo_2(int n) {
    int* answers = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        answers[i] = -1;
    }
    return fibo_helper(answers, n);
}

int main() {
    cout << fibo_3(10) << endl;
}