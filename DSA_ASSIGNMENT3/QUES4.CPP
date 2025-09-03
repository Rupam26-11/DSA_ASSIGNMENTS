#include <iostream>
#include <string>
using namespace std;
void push(int &top, char st[], char n)
{
	top=top+1;
    st[top] = n;
}
char pop(int &top, char st[])
{
    return st[top--];
}

int prior(char n)
{
    if (n=='+'||n=='-')
	 return 1;
    else if (n=='*'||n=='/')
	 return 2;
    else if (n=='^') 
	return 3;
    else
	 return 0;
}

int main()
{
    string check="2*(3+4)-6";
    int l=check.length();
    char st[100];
    string output="";
    int top=-1;
    for (int i=0;i<l;i++)
	 {
        char c=check[i];
        if (c>='0'&&c<='9')
		 {
            output=output+c;
}
        else if (c=='(')
		{
            push(top,st,c);
        }
        else if (c==')')
		{
            while (top!=-1&&st[top]!='(')
			{
                output=output+pop(top, st);
            }
            if (top!=-1 && st[top]=='(')
			{
                pop(top,st); 
            }
        }
         else
		 {
            while (top!=-1 && prior(st[top])>= prior(c)) 
			{
                    if (c=='^'&& prior(st[top])==prior(c))
					 break;
                output=output+pop(top, st);
            }
            push(top,st,c);
        }
    }
    while (top!=-1) 
	{
        output=output+pop(top,st);
    }
	cout<<"Postfix "<<output<< endl;
    return 0;
}
