//I:a a b c ; O: a -1 b b
#include<iostream>
#include<string>
using namespace std;

int main()
{
	char q[]={'a','a','b','c'};
	char a[26];int fr[256]={0};
	int f=0;int e=-1;
	for(int i=0;i<4;i++)
	{
		char ch=q[i];
		fr[(int)ch]++;
		e++;
		a[e]=ch;
		while(f<=e && fr[(int)a[f]]>1)
		{
			f++;
		}
		if(f>e)
		{
			cout<<"-1"<<" ";
		}
		else
		{
			cout<<a[f]<<" ";
		}
	}
	
}