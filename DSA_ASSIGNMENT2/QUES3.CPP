#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
     cin>>a[i];
    int total=(n+1)*(n+2)/2;
    int sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    cout<<total-sum;
}
