//transpose of sparse
#include <iostream>
using namespace std;
int main() {
    int r,c,n;
    cout<<"Enter row col and non zero elements"<<endl;
    cin>>r>>c>>n;
	 int a[n][3];  
    int t[100][3];
    a[0][0] = r;
    a[0][1] = c;
    a[0][2] = n;


    for (int i = 1; i <= n; i++) {
    	    cout << "Enter row col and value";
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cout << "a triplet-"<<endl;
     for (int i = 0; i <= n; i++) {
        cout << a[i][0] << "  " << a[i][1] << "  " << a[i][2] << endl;
    }
	 t[0][0] = a[0][1]; 
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    int k = 1;
    for (int i= 0; i<=c; i++) {
        for (int j = 1; j<= n;j++) {
            if (a[j][1] == i) {
                t[k][0] = a[j][1];
                t[k][1] = a[j][0];
                t[k][2] = a[j][2];
                k++;
            }
        }
    }

    cout << "Transpose of A in Triplet form"<<endl;
       for (int i = 0; i <= n; i++) {
        cout << t[i][0] << "  " << t[i][1] << "  " << t[i][2] << endl;
    }
}
