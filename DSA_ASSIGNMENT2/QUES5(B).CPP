#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int size=3*n-2;
    int a[size];
    for(int i=0;i<size;i++) cin>>a[i];
    int r,c;
    cin>>r>>c;
    if(r-c==0) cout<<a[r-1];
    else if(r-c==1) cout<<a[n-1+r-1];
    else if(c-r==1) cout<<a[2*n-1+r-1];
    else cout<<0;
    return 0;
}
