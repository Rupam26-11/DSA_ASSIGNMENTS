#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else break;
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i)
        heapifyMax(arr, n, i);
}

void heapSortAscending(int arr[], int n) {
    if (n <= 1) return;
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    while (true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[left] < arr[smallest]) smallest = left;
        if (right < n && arr[right] < arr[smallest]) smallest = right;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            i = smallest;
        } else break;
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i)
        heapifyMin(arr, n, i);
}

void heapSortDescending(int arr[], int n) {
    if (n <= 1) return;
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << (i+1==n?'\n':' ');
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int *b = new int[n];
    for (int i = 0; i < n; ++i) b[i] = a[i];
    heapSortAscending(a, n);
    printArray(a, n);
    heapSortDescending(b, n);
    printArray(b, n);
    delete[] a;
    delete[] b;
    return 0;
}
