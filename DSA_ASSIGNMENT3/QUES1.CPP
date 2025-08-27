#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    int* stack = new int[size];
    int top = -1;
    int choice, item;

    while (1) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (top == size - 1) cout << "\nStack is Full\n";
            else {
                cout << "Enter element to push: ";
                cin >> item;
                top++;
                stack[top] = item;
                cout << item << " pushed\n";
            }
        }
        else if (choice == 2) {
            if (top == -1) cout << "\nStack is Empty\n";
            else {
                cout << stack[top] << " popped\n";
                top--;
            }
        }
        else if (choice == 3) {
            if (top == -1) cout << "\nStack is Empty\n";
            else cout << "\nStack is not Empty\n";
        }
        else if (choice == 4) {
            if (top == size - 1) cout << "\nStack is Full\n";
            else cout << "\nStack is not Full\n";
        }
        else if (choice == 5) {
            if (top == -1) cout << "\nStack is Empty\n";
            else {
                cout << "\nStack elements: ";
                for (int i = top; i >= 0; i--) cout << stack[i] << " ";
                cout << "\n";
            }
        }
        else if (choice == 6) {
            if (top == -1) cout << "\nStack is Empty\n";
            else cout << "\nTop element is: " << stack[top] << "\n";
        }
        else if (choice == 7) {
            delete[] stack;
            return 0;
        }
        else cout << "\nInvalid Choice\n";
    }
}
