#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    

    string str[50], temp;

    cout << "Enter " << n << " strings:" << endl;
    for(int i = 0; i < n; i++) {
        getline(cin, str[i]);
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    cout << "\nStrings in alphabetical order:" << endl;
    for(int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
