#include <iostream>
using namespace std;
void enqueue(int q[],int &e,int val) 
{ e++;
	q[e] = val;
 }
int dequeue(int q[],int &f,int &rear)
 { f++;
 return q[f];
  }

void push(int q1[],int &f1,int &r1,int q2[],int &f2,int &r2,int x)
 {
    enqueue(q1,r1,x);
}

int pop(int q1[], int &f1, int &r1, int q2[], int &f2, int &r2) {
    if(f1 > r1) 
	return -1;
    while(f1 < r1)
	 enqueue(q2, r2, dequeue(q1, f1, r1));
    int val = dequeue(q1, f1, r1);
    swap(q1, q2);
	 swap(f1, f2);
	  swap(r1, r2);
    return val;
}

int main() {
    int q1[100], q2[100];
    int f1=0, r1=-1, f2=0, r2=-1;
    push(q1,f1,r1,q2,f2,r2,10);
    push(q1,f1,r1,q2,f2,r2,20);
    push(q1,f1,r1,q2,f2,r2,30);
    cout << pop(q1,f1,r1,q2,f2,r2) << " ";
    cout << pop(q1,f1,r1,q2,f2,r2) << " ";
    push(q1,f1,r1,q2,f2,r2,40);
    cout << pop(q1,f1,r1,q2,f2,r2) << " ";
    cout << pop(q1,f1,r1,q2,f2,r2) << " ";

}
