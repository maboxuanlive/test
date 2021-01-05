#include <iostream>

using namespace std;

int main()
{
    int temp,i,a,b[100],j=0;
    cin>>temp>>i;
    string s="ABCDEF";
    while(temp%i!=0||temp/i!=0)
    {
        a=temp/i;
        b[j++]=temp%i;
        temp=a;
    }
    j--;
    while(j>=0)
    {
        if(b[j]>9)
            if((b[j]-10)<6)
              cout<<s[b[j]-10];
            else
            	cout<<s[5];
        else
            cout<<b[j];
        j--;
    }
    return 0;
}




