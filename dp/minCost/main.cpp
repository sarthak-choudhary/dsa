#include <iostream>

using namespace std;
// Question : you will get a 2D integer array, you have two travel from one end to the other
// covering the min sum of the path

//input : m n (dimensions of array)
//        X X X X
//        X X X X
//        X X X X (input for the array)

//output : (int) minimum cost
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

int minCost(int** input, int** answers, int endX, int endY) {

    for (int i = endX; i >= 0; i--) {
        for (int j = endY; j >= 0; j--) {
            if (i == endX && j == endY) {
                answers[i][j] = input[i][j];
            } else if (j < endY && i < endX) {
                int a = answers[i][j + 1];
                int b = answers[i + 1][j + 1];
                int c = answers[i + 1][j];
                int min = minimum(a, b, c);

                answers[i][j] = input[i][j] + min;
            } else if (j < endY) {
                int a = answers[i][j + 1];
                answers[i][j] = input[i][j] + a;
            } else if (i < endX) {
                int c = answers[i + 1][j];
                answers[i][j] = input[i][j] + c;
            }
        }
    }

    return answers[0][0];
}

int main() {
    // dimensions of the array
    int m {};
    int n {};

    cin >> m;
    cin >> n;

    // Input for the array
    int** input = new int*[m];
    for (int i = 0; i < m; i++) {
        input[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    int** answers = new int*[m];
    for (int i = 0; i < m; i++) {
        answers[i] = new int[n];
    }

    cout << minCost(input, answers, m - 1, n - 1) << endl;

}