#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int st = 0, end = n - 1;

    while (st < end) {
        int min_idx = st;
        int max_idx = st;

        for (int i = st; i <= end; i++) {
            if (arr[i] < arr[min_idx])
                min_idx = i;
            if (arr[i] > arr[max_idx])
                max_idx = i;
        }

        // Swap minimum element with start
        int temp = arr[st];
        arr[st] = arr[min_idx];
        arr[min_idx] = temp;

        // If max element was at start, it is now at min_idx
        if (max_idx == st)
            max_idx = min_idx;

        // Swap maximum element with end
        temp = arr[end];
        arr[end] = arr[max_idx];
        arr[max_idx] = temp;

        st++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
