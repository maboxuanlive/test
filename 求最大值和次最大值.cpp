#include <iostream>

using namespace std;
void getMax(int A[],int n,int &fMax,int &sMax){
      int i=0;
        fMax=sMax=0;
    	for(i=0;i<n;i++)
    	{
    	   if(fMax<A[i])
    	   {
    	   	sMax=fMax;
    	   	fMax=A[i];
    	   	continue;
    	   }
    	   if(sMax<A[i])
    	   {
    	   	sMax=A[i];
    	   }
    	 } 

}
int main()
{
    int n,maxV,nMax;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    getMax(a,n,maxV,nMax);
    cout<<maxV<<" "<<nMax<<endl;
    return 0;
}


