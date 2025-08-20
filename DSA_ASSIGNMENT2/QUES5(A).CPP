#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n],val;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int r,c;
    cin>>r>>c;
    if(r==c) cout<<a[r-1];
    else cout<<0;
    return 0;
}
