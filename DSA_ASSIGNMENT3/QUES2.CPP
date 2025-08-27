#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    char stack[100];
    int top = -1;

    int i = 0;
    while (str[i] != '\0') {
        top++;
        stack[top] = str[i];
        i++;
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top];
        top--;
    }
    cout << endl;

    return 0;
}
