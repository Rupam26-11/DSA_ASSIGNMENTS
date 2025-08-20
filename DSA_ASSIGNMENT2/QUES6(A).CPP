#include <iostream>
using namespace std;
int main() {
    int r,c,n;
    cin>>r>>c>>n;
    int a[n+1][3],b[n+1][3];
    a[0][0]=r; a[0][1]=c; a[0][2]=n;
    for(int i=1;i<=n;i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    b[0][0]=a[0][1]; b[0][1]=a[0][0]; b[0][2]=a[0][2];
    int k=1;
    for(int i=0;i<a[0][1];i++) {
        for(int j=1;j<=n;j++) {
            if(a[j][1]==i) {
                b[k][0]=a[j][1];
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }
        }
    }
    for(int i=0;i<=n;i++) {
        cout<<b[i][0]<<" "<<b[i][1]<<" "<<b[i][2]<<endl;
    }
    return 0;
}
