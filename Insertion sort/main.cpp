#include <iostream>
#include <chrono>

using namespace std;

void insertionSort(int arr[], int n) {
    if (n <= 1)
        return;

    insertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}


int main() {
    int arr[] = {43,23,54,12,32,64,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = chrono::high_resolution_clock::now();

    insertionSort(arr, n);


    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    double duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "excution time : " << duration << " ms" << endl;

    return 0;
}
