#include <iostream>
using namespace std;
void enqueue(int q[],int &e,int val) 
{ e++;
q[e] = val;
 }
int dequeue(int q[],int &f,int &rear)
 { 
 f++;
 return q[f];
  }

void push(int q[],int &f,int &r,int x) 
{
    enqueue(q,r,x);
    int n=r-f;
    for(int i=0;i<n;i++) 
	enqueue(q,r,dequeue(q, f, r));
}

int pop(int q[],int &f,int &r)
 {
    if(f>r)
	 return -1;
    return dequeue(q,f,r);
}

int main() {
    int q[100], f=0, r=-1;

    push(q,f,r,10);
    push(q,f,r,20);
    push(q,f,r,30);

    cout<<pop(q,f,r)<<" ";
    cout<<pop(q,f,r)<<" ";
    push(q,f,r,40);
    cout<<pop(q,f,r)<<" ";
    cout<<pop(q,f,r)<<" ";

 
}
