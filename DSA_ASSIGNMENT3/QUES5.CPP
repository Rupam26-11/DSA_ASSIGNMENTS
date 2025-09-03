//Write a program for the evaluation of a Postfix expression. 
#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
void push(int &top,int st[],int n)
{	top++;
    st[top] = n;
}
int pop(int &top,int st[])
 {	
    return st[top--];
}
int Postfix(string exp)
{
    int st[100];
    int top = -1;
    for (int i=0;i<exp.length();i++)
	{
        char c = exp[i];
        if (c>='0' && c <='9')
		 {
            push(top,st,c-'0');  
        }
        else
		 {  int val2 = pop(top,st);
            int val1 = pop(top,st);
            
            switch (c)
			 {
                case '+':
				 push(top,st,val1 + val2); 
				break;
                case '-':
				 push(top,st,val1 - val2);
				 break;
                case '*':
				 push(top,st,val1 * val2);
				  break;
                case '/': 
				push(top,st,val1 / val2); 
				break;
                case '^': 
				push(top,st,pow(val1, val2)); break;
            }
        }
    }

    return pop(top, st);
}

int main() {
    string postfix = "456+*6-"; 
    cout << "Postfix Expression " <<postfix << endl;
    cout << "Evaluation Result " <<Postfix(postfix) << endl;
    return 0;
}

