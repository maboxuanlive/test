#include <iostream>
#include <string>
using namespace std;
void judge(string str1,string str2,string str3)
{
    int i=0;
    int j=0;
    bool a1=0,a2=0;
    while(i<str1.length())
    {
        if(str1[i]==str3[j])
        {
            i++;
            j++;
        }
        else
            i++;
        if(j==str3.length())
            a1=1;
    }
    int i1=0,j1=0;
    while(i1<str2.length())
    {
        if(str2[i1]==str3[j1])
        {
            i1++;
            j1++;
        }
        else
            i1++;
        if(j1==str3.length())
            a2=1;
    }
    if(a1&&a2)
        cout<<"YES";
    else
        cout<<"NO";
}
int main()
{
    string str1;
    string str2;
    string str3;
    cin>>str1>>str2>>str3;
    judge(str1,str2,str3);
}



