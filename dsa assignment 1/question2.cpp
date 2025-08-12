#include <iostream>
using namespace std;

int main() {
    int arr[100], temp[100];
    int n, newSize = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[newSize] = arr[i];
            newSize++;
        }
    }

    
    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < newSize; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}
