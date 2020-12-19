#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {1, 3, 2, 5, 7, 6};
    // sort(arr, arr + 6); // to sort in ascending order
    sort(arr, arr + 6, greater<int>());

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}