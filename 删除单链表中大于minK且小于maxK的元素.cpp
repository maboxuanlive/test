#include <iostream>
using namespace std;

typedef int DataType;
typedef struct node{
    DataType data;
    node* next;
}node;
node *first;

void init( )
{
    first = new node;
    first->next = NULL;
    node* rear = first;
    int length;
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
void deleteList(DataType minK,DataType maxk)
{
   
             node *r=first;
             node *q=first->next;
             while(q)
      {       if(q->data>minK&&q->data<maxk)
             {
             	node *t;
             	r->next=q->next;
             	t=q;
             	q=q->next;
             	delete t;
      	   }
      	   else
      	   {
      	   	r=q;
      	   	q=q->next;
      	   }
      }

}
void show( )
{
    node* p = first->next;
    if(p == NULL) cout<<"Empty";
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main()
{
    init();
    DataType minK,maxK;
    cin>>minK>>maxK;
    deleteList(minK,maxK);
    show();
    return 0;
}


