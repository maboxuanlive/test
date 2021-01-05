#include <iostream>

using namespace std;
const int maa=100;
class s
{
   char a[maa];
   char b[maa];
   int top,toq;
   public:
    s()
    {top=-1;
      toq=-1;
    }
    void push(char s)
    {
        if(s=='I')
            a[++top]=s;
        if(s=='O')
            b[++toq]=s;
        po();
    }
    void pop1 ()
    {
        top--;
    }
    void pop2()
    {
        toq--;
    }
    int  gettop()
    {
        if(toq>top)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int fi()
    {
        return top;
    }
    void po()
    {
        while(top>=toq&&toq>-1)
        {
            pop1();
            pop2();
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
        if(a.gettop()==0)
        {
            cout<<0;
            return 0;
        }
            }
    if(a.fi()>-1)
    {
        cout<<0;
    }
    else
        cout<<1;
    return 0;
}


