#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    char str[50][50],temp[50];
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int k=0;
            while(str[i][k]==str[j][k] && str[i][k]!='\0' && str[j][k]!='\0') {
                k++;
            }
            if(str[i][k]>str[j][k]) {
                int m=0;
                while(str[i][m]!='\0') {
                    temp[m]=str[i][m];
                    m++;
                }
                temp[m]='\0';
                m=0;
                while(str[j][m]!='\0') {
                    str[i][m]=str[j][m];
                    m++;
                }
                str[i][m]='\0';
                m=0;
                while(temp[m]!='\0') {
                    str[j][m]=temp[m];
                    m++;
                }
                str[j][m]='\0';
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<str[i]<<endl;
    }
    return 0;
}
