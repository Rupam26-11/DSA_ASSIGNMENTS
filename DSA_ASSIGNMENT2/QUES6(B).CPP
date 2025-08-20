#include <iostream>
using namespace std;
int main() {
    int r,c,n1,n2;
    cin>>r>>c;
    cin>>n1;
    int a[n1+1][3];
    a[0][0]=r; a[0][1]=c; a[0][2]=n1;
    for(int i=1;i<=n1;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    cin>>n2;
    int b[n2+1][3];
    b[0][0]=r; b[0][1]=c; b[0][2]=n2;
    for(int i=1;i<=n2;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
    int cmat[n1+n2+1][3];
    int i=1,j=1,k=1;
    while(i<=n1 && j<=n2) {
        if(a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1])) {
            cmat[k][0]=a[i][0]; cmat[k][1]=a[i][1]; cmat[k][2]=a[i][2]; i++; k++;
        } else if(b[j][0]<a[i][0] || (b[j][0]==a[i][0] && b[j][1]<a[i][1])) {
            cmat[k][0]=b[j][0]; cmat[k][1]=b[j][1]; cmat[k][2]=b[j][2]; j++; k++;
        } else {
            cmat[k][0]=a[i][0]; cmat[k][1]=a[i][1]; cmat[k][2]=a[i][2]+b[j][2]; i++; j++; k++;
        }
    }
    while(i<=n1) { cmat[k][0]=a[i][0]; cmat[k][1]=a[i][1]; cmat[k][2]=a[i][2]; i++; k++; }
    while(j<=n2) { cmat[k][0]=b[j][0]; cmat[k][1]=b[j][1]; cmat[k][2]=b[j][2]; j++; k++; }
    cmat[0][0]=r; cmat[0][1]=c; cmat[0][2]=k-1;
    for(int x=0;x<k;x++) cout<<cmat[x][0]<<" "<<cmat[x][1]<<" "<<cmat[x][2]<<endl;
    return 0;
}
