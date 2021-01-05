#include <iostream>
using namespace std;

const int MaxSize=100;
typedef int DataType;
DataType data[MaxSize];
int length;

void reverseList( )
{
        	int temp; 
        	for(int i=0;i<length/2;i++)
        	{
        		temp=data[i];
        		data[i]=data[length-i-1];
        		data[length-i-1]=temp;
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
    reverseList();
    show();
    return 0;
}


