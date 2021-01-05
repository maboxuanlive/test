#include <iostream>
using namespace std;

const int MaxSize=100;
typedef int DataType;
DataType data[MaxSize];
int length=0;

void insertList(DataType elem)
{
          int i=0;
             int j=0;
            while(elem>data[i]&&i<length)
             {
             	i++;
      
      	   }
      	   for(j=length;j>i;j--)
      	   {
      	   	data[j]=data[j-1];
      	   }
      	   data[i]=elem;
      	   length++;

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
    insertList(x);
    show();
    return 0;
}


