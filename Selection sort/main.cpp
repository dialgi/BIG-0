#include <iostream>
#include <chrono>

using namespace std;

void selectionSort(int arr[], int n, int index = 0) {
    if (index >= n - 1)
        return;

    int minIndex = index;

    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    swap(arr[index], arr[minIndex]);

    selectionSort(arr, n, index + 1);
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);


    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr, n);


    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    double duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "execution time " << duration << " ms" << endl;

    return 0;
}
