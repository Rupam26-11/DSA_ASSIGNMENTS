#include <iostream>
using namespace std;

void enqueue(int val, int a[], int &f, int &r, int size) {
    if ((f == (r + 1) % size)) {
        cout << "Queue is Full\n";
        return;
    }
    if (f == -1 && r == -1) {
        f = r = 0;
    } else {
        r = (r + 1) % size;
    }
    a[r] = val;
}

void dequeue(int a[], int &f, int &r, int size) {
    if (f == -1 && r == -1) {
        cout << "Queue is Empty\n";
        return;
    }
    if (f == r) {
        f = r = -1;
    } else {
        f = (f + 1) % size;
    }
}

void isEmpty(int f, int r) {
    if (f == -1 && r == -1)
        cout << "Queue is Empty\n";
    else
        cout << "Queue is not Empty\n";
}

void isFull(int f, int r, int size) {
    if ((f == (r + 1) % size))
        cout << "Queue is Full\n";
    else
        cout << "Queue is not Full\n";
}

void peek(int a[], int f, int r) {
    if (f == -1 && r == -1)
        cout << "Queue is Empty\n";
    else
        cout << "Front Element: " << a[f] << "\n";
}

void display(int a[], int f, int r, int size) {
    if (f == -1 && r == -1) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue Elements: ";
    int i = f;
    while (true) {
        cout << a[i] << " ";
        if (i == r) break;
        i = (i + 1) % size;
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the size of the queue: ";
    cin >> n;
    int q[n];
    int front = -1, rear = -1;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Full\n";
        cout << "4. Check if Empty\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        int ch;
        cin >> ch;

        if (ch == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            enqueue(val, q, front, rear, n);
        } else if (ch == 2) {
            dequeue(q, front, rear, n);
        } else if (ch == 3) {
            isFull(front, rear, n);
        } else if (ch == 4) {
            isEmpty(front, rear);
        } else if (ch == 5) {
            peek(q, front, rear);
        } else if (ch == 6) {
            display(q, front, rear, n);
        } else if (ch == 7) {
            break;
        } else {
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}
