#include <iostream>
using namespace std;

int main() {
    char exp[100];
    cout << "Enter an expression: ";
    cin >> exp;

    char stack[100];
    int top = -1;

    int i = 0;
    bool balanced = true;

    while (exp[i] != '\0') {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                balanced = false;
                break;
            }
            char last = stack[top];
            top--;
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                balanced = false;
                break;
            }
        }
        i++;
    }

    if (top != -1) balanced = false;

    if (balanced)
        cout << "Balanced Expression\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
