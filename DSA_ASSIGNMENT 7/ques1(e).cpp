#include <iostream>
using namespace std;

int partition(int arr[], int st, int end) {
    int piv = arr[end];
    int idx = st;

    for (int i = st; i < end; i++) {
        if (arr[i] <= piv) {
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
            idx++;
        }
    }

    int temp = arr[idx];
    arr[idx] = arr[end];
    arr[end] = temp;

    return idx;
}

void quickSort(int arr[], int st, int end) {
    if (st < end) {
        int piv_idx = partition(arr, st, end);
        quickSort(arr, st, piv_idx - 1);
        quickSort(arr, piv_idx + 1, end);
    }
}

int main() {
    int arr[] = {9, 4, 7, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
