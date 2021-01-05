#include<iostream>
#include<stdlib.h>
using namespace std;
class seqlist
{
private:
	int *listP;
	int maxsize;
	int sizeL;
public:
	seqlist(int maxL);
	~seqlist();
	int getSize();
	void Insert(int i,int item);
	int Delete( int i);
	int getdata(int i);
	void dispaly( );
};
//初始化顺序表
	seqlist::seqlist(int maxL)
	{
		maxsize=maxL;
		sizeL=0;
		listP=new int[maxL];
	}
//释放顺序表的空间
	seqlist::~seqlist()
	{
		delete []listP;
		maxsize=0;
		sizeL=0;
	}
//返回顺序表的长度
	int seqlist::getSize()
	{
		return sizeL;
	}
//在位置i处插入元素item
	void seqlist::Insert( int i,int item)
	{
	{
         if(i>sizeL)
          {
          	listP[i]=item;
          	sizeL=i;
          }
          else
          {
          for(int j=sizeL+1;j>i&&sizeL<=maxsize;j--)
          {
          	listP[j]=listP[j-1];
          }
          listP[i]=item;
          sizeL++;
      }
  

}

}
	//先返回位置i处的数据，在删除该数据
	int seqlist::Delete( int i)
	{
 int j;
          j=listP[i];
          for(int k=i;listP[k]!='\0';k++)
          {
          	listP[k]=listP[k+1];
          }
          sizeL--;
          return j;

}
//返回位置i处的数据
	int seqlist::getdata(int i)
	{
		if(i<1 || i>sizeL)
		{
			cout<<"参数越界错误!";
			exit(0);
		}
		return listP[i];
	}
//打印顺序表
	void seqlist::dispaly( )
	{
		for(int i=1;i<=sizeL;i++)
            cout<<listP[i]<<"  ";
        cout<<endl;
	}

	int main()
	{
	    int maxL=0,n=0,item,pos;
	    //cout<<"请输入顺序表的最大长度：";
	    cin>>maxL;
		seqlist mylist(maxL);
		//cout<<"请输入顺序表的数据的个数：";
	    cin>>n;
	   // cout<<"请依次输入"<<n<<"个数据：";
		for(int i=0;i<n;i++){
		    cin>>item;
            mylist.Insert(i+1,item);
		}
		//cout<<"请输入插入数据的位置和数值：";
        cin>>pos>>item;
        mylist.Insert(pos,item);
       // cout<<"执行插入操作后的顺序表：";
        mylist.dispaly();
        //cout<<"请输入删除数据的位置：";
        cin>>pos;
        mylist.Delete(pos);
        //cout<<"执行删除操作后的顺序表：";
        mylist.dispaly();
        return 1;
	}


