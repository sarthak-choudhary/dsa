#include <iostream>

using namespace std;

void mindBending(int* input, int length) {
    int left_product {1};
    int right_product {1};

    int* product = new int[length];
    product[0] = left_product;

    for (int i = 1; i < length; i++) {
        product[i] = left_product * input[i - 1];
        left_product = product[i]; 
    }

    for (int i = length - 2; i >= 0; i--) {
        product[i] = product[i] * right_product * input[i + 1];
        right_product = right_product * input[i + 1];
    }

    cout << "The Output array is :" << endl;

    for (int i = 0; i < length; i++) {
        cout << product[i] << " ";
    }

}

int main() {
    cout << "Enter the length of the input array" << endl;

    int length;
    cin >> length;

    int* input = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> input[i];
    }

    mindBending(input, length);
}