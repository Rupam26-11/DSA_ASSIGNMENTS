#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];  // static array for heap storage
    int size;      // number of elements in heap

public:
    PriorityQueue() {
        arr[0] = -1; // index 0 unused
        size = 0;
    }

    // Insert element into priority queue
    void push(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Heapify up
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Remove element with highest priority (root)
    void pop() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Heapify down
        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;
            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // Return element with highest priority
    int top() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[1];
    }

    // Check if empty
    bool empty() {
        return size == 0;
    }

    // Print heap elements
    void display() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(10);
    pq.push(60);
    pq.push(55);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Top element (highest priority): " << pq.top() << endl;

    pq.pop();
    cout << "After removing top element: ";
    pq.display();

    return 0;
}
