#include <iostream>
using namespace std;

typedef int DataType;
typedef struct node{
    DataType data;
    node* next;
}node;

//尾插法构造单链表
void init(node*&first,int len)
{
    first = NULL;
    node* rear;
    for(int i=0;i<len;++i){
        DataType elem;
        cin>>elem;
        node* s = new node;
        s->data = elem;
        s->next = NULL;
        if(first == NULL){
            first = s;
            rear = first;
        }
        else{
           rear->next = s;
           rear = s;
        }
    }
}
//八进制A加八进制B，结果存在链表A中
void add(node* A,node* B)
{
          node*r=A;
          node*s=B;
          node*c;
          int i=0,j=0,temp=0;
          while(r->next)
          {
          	i++;
          	r=r->next;
        
          }
          while(s->next)
          {
          	j++;
          	s=s->next;
          }
        	while(i<j)
        	{
        		node*p=new node;
        		r->next=p;
        		p->next=NULL;
        		p->data=0;
        		r=p;
        		i++;
        	}
          	while(j<i)
        	{
        		node*p=new node;
        		s->next=p;
        		p->next=NULL;
        		p->data=0;
        		s=p;
        		j++;
        	}
        	r=A;
        	s=B;
        	  while(r||s)
          {
          	r->data=r->data+s->data+temp;
          	temp=0;
          	if(r->data>=8)
          	{
          		temp=r->data/8;
          		r->data=r->data%8;
        	  }
        	  c=r;
        	  r=r->next;
        	  s=s->next;
          }
        	if(temp>0)
        	{
        		node *p=new node;
        		p->data=temp;
        		p->next=NULL;
        		c->next=p;
        	}

}

void reverseList(node* &first)
{
        int i=1,j=0,z,k,temp,length=0;
               node* r;
               node* t;
               r=first; 
               while(r)
      		 {
      		 	length++;
      		 	r=r->next;
      		  } 
      		  j=length;
             while(i<=length/2)
             {
             		r=t=first;
      			k=z=1;
             		while(k<i)
             		{
             			r=r->next;
             			k++;
      			   }
      			   i++;
      		   if(j>length/2)
      		   {
      		   	while(z<j)
      		   	{
      		   		t=t->next;
      		   		z++;
      			   }
      			     j--;
      		   }
      		   		   temp=t->data;
      		   t->data=r->data;
      		   r->data=temp;
      
      	}

}
void show(node* first)
{
    node* p = first;
    if(p == NULL) cout<<"Empty";
    else{
        while(p != NULL){
            cout<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    node*A,*B;
    int aLen,bLen;
    cin>>aLen;
    init(A,aLen);
    cin>>bLen;
    init(B,bLen);

    reverseList(A);
    reverseList(B);

    add(A,B);
    reverseList(A);
    show(A);
    return 0;
}


