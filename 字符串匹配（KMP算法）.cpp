#include <iostream>
using namespace std;

void saddlePoint(int** A,int n,int m)
{
   int min1[n+1];
          int max2[m+1];
          for(int i=1;i<=n;i++)
           max2[i]=0;
          for(int i=1;i<=m;i++)
           min1[i]=9999999;
          for(int i=1;i<=n;i++)
           for(int j=1;j<=m;j++)
          {
              if(min1[i]>A[i][j])
               min1[i]=A[i][j];
          }
          for(int i=1;i<=m;i++)
           for(int j=1;j<=n;j++)
          {
              if(max2[i]<A[j][i])
               max2[i]=A[j][i];
          }
          bool judge=1;
          for(int i=1;i<=n;i++)
           for(int j=1;j<=m;j++)
          {
              if(A[i][j]==min1[i]&&A[i][j]==max2[j])
               {
                   cout<<A[i][j]<<" "<<i<<" "<<j<<endl;
                   judge=0;
               }
          }
          if(judge)
           cout<<"No answer";

}
int main()
{
    int n,m;
    cin>>n>>m;
    int** arr = new int*[n+1];
    for(int i=0;i<= n+1;++i)
        arr[i] = new int[m+1];

    for(int i=1;i<= n;++i)
        for(int j=1;j<= m;++j)
            cin>>arr[i][j];

    saddlePoint(arr,n,m);
    return 0;
}


