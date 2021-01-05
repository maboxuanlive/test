#include <iostream>
using namespace std;

bool judge(string str){
int p=1;
for(int i=0,j=str.size()-1;i!=j;i++,j--)
{if(str[i]==str[j]) {p=1;
continue;}
if(str[i]!=str[j])
{ p=0;break;}
}
if(p==1)return 1;
if(p==0)return 0;

}
int main()
{
    string s;
    getline(cin,s);
    bool res=judge(s);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}


