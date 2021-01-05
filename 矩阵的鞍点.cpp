#include<cstring>
#include<iostream>
#include<string>
using namespace std;

void getNext(string T,int length, int next[])//计算next函数值
{
   
   
   next[0]=-1;
       next[1]=0;
       for(int i=2;i<length;i++)
       {
           int m=0;
           for(int a=1,r=i-1;a<i;a++)//比较的次数
           {
               bool judge=1;
               for(int j=0;j<a;j++,r--)
               {
                   if(T[j]!=T[r])
                       judge = 0;
               }
               if (judge)
                   m=a;
           }
           next[i]=m;
       }

}

int Index_KMP(string S, int sLen,string T,int tLen, int pos, int next[])//KMP算法
{
    
    int i=0,j=0;
        while(i<sLen&&j<tLen)
        {
            bool judge=1;
            if(S[i]==T[j])
            {
                i++;
                j++;
            }
            else if(S[i]!=T[j])
            {
                judge=0;
                if(next[j]==-1)
                {
                    if(tLen!=1)
                    {i++;j=0;}
                    else
                        i++;
                }
                else
                    j=next[j];
            }
            if(j==tLen&&judge)
                return i-j+1;
        }
        return 0;

}
void show(int *arr,int len)
{
    for(int i=0;i<len;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    string S,T;
    getline(cin,S);
    getline(cin,T);
    int SLength,TLength;
	SLength=S.length();
	TLength=T.length();
    int *p=new int[TLength]; //生成T的next数组
    getNext(T,TLength,p);
    cout<<Index_KMP(S,SLength,T,TLength,0,p)<<endl;
    show(p,TLength);
    return 0;
}

