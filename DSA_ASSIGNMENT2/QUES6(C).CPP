#include <iostream>
using namespace std;
int main() {
    int r1,c1,n1,r2,c2,n2;
    cin>>r1>>c1>>n1;
    int a[n1+1][3];
    a[0][0]=r1; a[0][1]=c1; a[0][2]=n1;
    for(int i=1;i<=n1;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    cin>>r2>>c2>>n2;
    int b[n2+1][3];
    b[0][0]=r2; b[0][1]=c2; b[0][2]=n2;
    for(int i=1;i<=n2;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
    if(c1!=r2) { cout<<"Invalid"; return 0; }
    int cmat[1000][3]; int k=1;
    cmat[0][0]=r1; cmat[0][1]=c2;
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++) {
            int sum=0;
            for(int p=1;p<=n1;p++) {
                if(a[p][0]==i) {
                    for(int q=1;q<=n2;q++) {
                        if(b[q][0]==a[p][1] && b[q][1]==j) {
                            sum+=a[p][2]*b[q][2];
                        }
                    }
                }
            }
            if(sum!=0) {
                cmat[k][0]=i;
                cmat[k][1]=j;
                cmat[k][2]=sum;
                k++;
            }
        }
    }
    cmat[0][2]=k-1;
    for(int i=0;i<k;i++) cout<<cmat[i][0]<<" "<<cmat[i][1]<<" "<<cmat[i][2]<<endl;
    return 0;
}
