#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[100];
    cin.getline(str,100);
    int n=strlen(str);
    for(int i=n-1;i>=0;i--) {
        cout<<str[i];
    }
    return 0;
}
