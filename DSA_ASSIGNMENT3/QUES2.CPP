#include <iostream>
#include <string>
using namespace std;

void push(int &top, char ch, char st[], int size) 
{
    if (top < size - 1) {
        st[++top] = ch;
    } else {
        cout << "Stack Overflow! Cannot push " << ch << endl;
    }
}

char pull(int &top, char st[]) 
{
    if (top >= 0) {
        return st[top--];
    } else {
        return '\0';
    }
}

int main() {
    string name = "Datastructures";
    char st[100];
    int top = -1;

    for (int i = 0; i < name.length(); i++) {
        push(top, name[i], st, 100);
    }

    string reversed = "";
    for (int i = 0; i < name.length(); i++) {
        reversed += pull(top, st);
    }

    cout << "Initial string: " << name << endl;
    cout << "Reversed string: " << reversed << endl;
}
