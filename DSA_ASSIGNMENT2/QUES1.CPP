#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    int key;
    cin>>key;
    int l=0,r=n-1,pos=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key)
        {pos=m;break;}
        else if(a[m]<key) 
        l=m+1;
        else 
        r=m-1;
    }
    if(pos==-1) cout<<"Not found";
    else cout<<"Found at index "<<pos;
}
