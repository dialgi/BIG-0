#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearchRecursive(int arr[], int n, int target) {
    if (n < 0) {
        return -1;
    }

    if (arr[n] == target) {
        return n;
    }

    return linearSearchRecursive(arr, n - 1, target);
}

int main() {
    int arr[] = {3,2,4,6,1,7,9,5,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;


    auto start = high_resolution_clock::now();
    int index = linearSearchRecursive(arr, n - 1, target);
    auto stop = high_resolution_clock::now();

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }


    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
