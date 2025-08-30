//Addition of the two matrices
#include<iostream>
using namespace std;
int main()
{
	int r,c,n;
	cout<<"Enter numbe rof row col and the value";
	cin>>r>>c>>n;
	int a[r][3];
	for(int i=0;i<n;i++)
	{	cout<<"enter the row then col and value ";
		for(int j=0;j<3;j++)
		{	
			cin>>a[i][j];
		}
	}	cout<<"triplet"<<endl;
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{	
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
		int r1,c1,n1;
	cout<<"Enter numbe rof row col and the value of second";
	cin>>r1>>c1>>n1;
	int b[r1][3];
	for(int i=0;i<n1;i++)
	{	cout<<"enter the row then col and value ";
		for(int j=0;j<3;j++)
		{	
			cin>>b[i][j];
		}
	}	cout<<"second triplet"<<endl;
		for(int i=0;i<n1;i++)
	{
		for(int j=0;j<3;j++)
		{	
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
int s[n + n1][3];
    int i = 0, j = 0, k = 0;


    while (i < n && j < n1) {
                if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) 
				{
            s[k][0] = a[i][0];
            s[k][1] = a[i][1];
            s[k][2] = a[i][2];
            i++;
        } 
		else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1]))
		 {
            s[k][0] = b[j][0];
            s[k][1] = b[j][1];
            s[k][2] = b[j][2];
            j++;
        }
		 else 
		 {
            s[k][0] = a[i][0];
            s[k][1] = a[i][1];
            s[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }

   
    while (i < n)
	 {
        s[k][0] = a[i][0];
        s[k][1] = a[i][1];
        s[k][2] = a[i][2];
        i++; k++;
    }
    while (j < n1) {
        s[k][0] = b[j][0];
        s[k][1] = b[j][1];
        s[k][2] = b[j][2];
        j++; k++;
    }

    cout << "Result triplet ";
    for (int i = 0; i < k; i++) {
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
    }

    return 0;
}
