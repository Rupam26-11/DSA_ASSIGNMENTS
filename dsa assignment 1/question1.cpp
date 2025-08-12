#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n = 0;

void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, val;
    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos - 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch() {
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Element not found\n";
    }
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            createArray();
        }
        else if (choice == 2) {
            displayArray();
        }
        else if (choice == 3) {
            insertElement();
        }
        else if (choice == 4) {
            deleteElement();
        }
        else if (choice == 5) {
            linearSearch();
        }
        else if (choice == 6) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
