#include <iostream>
using namespace std;

typedef int DataType;
typedef struct node{
    DataType data;
    node* next;
}node;
node* first;
int length;

void init()
{
    first = new node;
    first->next = NULL;
    node* rear = first;
    cin>>length;
    for(int i=0;i<length;++i){
        DataType elem;
        cin>>elem;
        node* s = new node;
        s->data = elem;
        s->next = NULL;
        rear->next = s;
        rear = s;
    }
}
void reverseList()
{
             int i=0,j=length,z,k,temp;
                 node* r;
                 node* t;
               while(i<length/2)
               {
               		r=t=first;
        			k=z=0;
               		while(k<=i)
               		{
               			r=r->next;
               			k++;
        			   }
        			   i++;
        		   if(j>=length/2)
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
void show()
{
    node* p = first->next;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main()
{
    init();
    reverseList();
    show();
    return 0;
}


