#include <iostream>
using namespace std;
int main() {
    int r1,c1,r2,c2;
    cin >> r1 >> c1;
    int a[r1][c1];
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> a[i][j];
    cin >> r2 >> c2;
    int b[r2][c2];
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin >> b[i][j];
    if(c1!=r2) {
        cout << "Not possible";
        return 0;
    }
    int res[r1][c2] = {0};
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
                res[i][j] += a[i][k] * b[k][j];
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
