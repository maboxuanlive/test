#include <iostream>
using namespace std;
void split(int A[],int n){
      int i=0,j=n-1;
      while(i<j)
      {if(A[i]%2==0&&A[j]%2!=0)
      {int t=A[j];
      A[j]=A[i];
      A[i]=t;i++;j--;}
      
      
      
      if(A[i]%2!=0) i++;
      if(A[j]%2==0) j--;
      
      }

}
void show(int A[],int n){
    for(int i=0;i<n;++i)
        cout<<A[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    split(a,n);
    show(a,n);
    return 0;
}


