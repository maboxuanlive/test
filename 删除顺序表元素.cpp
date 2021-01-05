#include <iostream>
using namespace std;

const int MaxSize=100;
typedef int DataType;
DataType data[MaxSize];
int length;

void deleteList(DataType elem)
{
        		DataType i=0;
        	for(;i<length;)
        	{
        		if( data[i]==elem)
        		{
        			int j=i;
        	     while(j<length)
        	     {
        	     	data[j]=data[j+1];
        	     	j++;
        	     }
        	     length--;
        		}
        		else
        		{
        			i++;
        		}
        	}

}
void show()
{
    for(int i=0;i<length;++i)
        cout<<data[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>length;
    for(int i=0;i<length;++i)
        cin>>data[i];
    DataType x;
    cin>>x;
    deleteList(x);
    show();
    return 0;
}


