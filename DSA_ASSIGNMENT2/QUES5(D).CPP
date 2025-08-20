#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int size=n*(n+1)/2;
    int a[size],k=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            cin>>a[k++];
        }
    }
    int r,c;
    cin>>r>>c;
    if(r<=c) cout<<a[(r-1)*n-(r-2)*(r-1)/2+c-r];
    else cout<<0;
    return 0;
}
