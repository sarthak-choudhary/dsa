#include <iostream>

using namespace std;

int kadane(int* arr, int n) {
    int best_so_far {};
    int current_best {};

    for (int i = 0; i < n; i++) {
        current_best += arr[i];
        if (current_best < 0) {
            current_best = 0;
        }

        if (current_best > best_so_far) {
            best_so_far = current_best;
        }
    }

    return best_so_far;
}


int main() {

    int n;
    cout << "Enter the length of the array" << endl;
    cin >> n;
    int* input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << "The Maximum Sum SubArray is " << kadane(input, n) << endl;

}