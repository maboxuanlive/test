#include <iostream>
#include<string>

using namespace std;

int main()
{

    int i;
    cin>>i;
    int a[i];
    int j;
    for( j=0;j<i;j++)
    {
        cin>>a[j];
    }
    for(j=0;j<i;j++)
    {
        if(a[j]==0)
        {
            int z=j;
            while(z<i)
            {
                if(a[z]!=0)
                {
                    a[j]=a[z];
                    a[z]=0;
                    break;
                }
                z++;
            }
        }
    }
    for(j=0;j<i;j++)
    {
        cout<<a[j]<<" ";
    }
    return 0;
}




