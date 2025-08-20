#include <iostream>
using namespace std;
int main() {
    char str1[100], str2[100];
    cin.getline(str1,100);
    cin.getline(str2,100);
    int i=0,j=0;
    while(str1[i]!='\0') {
        i++;
    }
    while(str2[j]!='\0') {
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';
    cout<<str1;
    return 0;
}
