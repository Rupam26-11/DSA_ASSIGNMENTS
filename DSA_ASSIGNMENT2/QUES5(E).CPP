#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int size = n*(n+1)/2;
    int a[size];

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> a[i*(i+1)/2 + j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j)
                cout << a[i*(i+1)/2 + j] << " ";
            else
                cout << a[j*(j+1)/2 + i] << " "; // symmetric
        }
        cout << endl;
    }

    return 0;
}
