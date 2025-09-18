//S: 4 7 11 20 5 9 ; o: 4 20 7 5 11 9
#include<iostream>
using namespace std;
int deq(int q[],int &f,int &e)
{
	int d=q[f];
	f++;
	
	return d;
}
int enq(int q[],int &f,int &e,int n)
{
	e++;
	q[e]=n;
}

int main ()
{
	int q[]={4,7,11,20,5,9};
	int front=0,end=5;
	int a[3];int c[10];
	int t=0;int b=-1;
	for(int i=0;i<3;i++)
	{
	int e=deq(q,front,end);
	enq(a,t,b,e);
	}
	int p=0;
for(int i=0;i<3;i++)
{
	c[p]=deq(a,t,b);
	p++;
	c[p]=deq(q,front,end);
	p++;

}
cout<<"final output"<<endl;
for(int i=0;i<6;i++)
{
	cout<<c[i]<<endl;
}
}