#include <iostream>

using namespace std;
const int maa=100;
class s
{
   char a[maa];
   int top;
   public:
    s(){top=-1;}
    void push(char s)
    {
        int i;
        if (top==-1)
        {
            a[++top]=s;
        }
        else
        {i=po(s,a[top]);
        if(i==0)
        {
        a[++top]=s;}
        if(i==1)
        {
            pop();
        }}
            }
    void pop ()
    {
        top--;
    }
    int  gettop()
    {
        int i=top;
        return i;
    }
   int  po(char s,char st)
   {
       switch(st)
    {
    case '(':
        if(s==')')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
        case '[':
        if(s==']')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
        case '{':
        if(s=='}')
        {
            return 1;
        }
        else
        {
            return 0;
        }
        break;
    }
   }
};

int main()
{
    s a;
    string b;
    int i;
    cin>>b;
    for(i=0;b[i]!='\0';i++)
    {
        a.push(b[i]);
            }
    i=a.gettop();
    if(i==-1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}


