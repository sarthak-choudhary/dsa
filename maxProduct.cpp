#include <iostream>
#include <algorithm>

using namespace std;

int maxProduct(int* input, int length) {
    int max_ending {1};

    int max_ending_here {1};
    int min_ending_here {1};

    for (int i = 0; i < length; i++) {
        if (input[i] > 0) {
            max_ending_here = max_ending_here * input[i];
            min_ending_here = min(1, min_ending_here * input[i]);
        } else if (input[i] < 0) {
            int temp = min_ending_here;
            min_ending_here = max_ending_here * input[i];

            max_ending_here = max(1, temp * input[i]);
        } else {
            min_ending_here = 1;
            max_ending_here = 1;
        }

        if (max_ending < max_ending_here) {
            max_ending = max_ending_here;
        }
    }

    return max_ending;

}

int main() {
    int length;
    cout << "Enter the length of input array" << endl;

    cin >> length;

    int* input = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> input[i];
    }

    cout << "Max Product Subarray is " <<  maxProduct(input, length)  << endl;
}
