#include <iostream>
#include <chrono>

using namespace std;

void bubbleSort(int arr[], int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }


    bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {12,32,54,23,65,24,21};
    int n = sizeof(arr) / sizeof(arr[0]);


    auto start = chrono::high_resolution_clock::now();

    bubbleSort(arr, n);


    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    double duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "execution time : " << duration << " ms" << endl;

    return 0;
}
