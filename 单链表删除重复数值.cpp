#include <iostream>
using namespace std;

template <class DataType>
struct node{
DataType data;
node<DataType>* next;
};

template <class DataType>
class linkList{
    public:
        linkList();
        ~linkList();
        void Delete();
        void show();
    private:
        node<DataType>* first;
};

template <class DataType>
linkList<DataType>::linkList()
{
    first = new node<DataType>;
    first->next = NULL;
    node<DataType>* rear = first;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        DataType elem;
        cin>>elem;
        node<DataType>* s = new node<DataType>;
        s->data = elem;
        s->next = NULL;
        rear->next = s;
        rear = s;
    }
}
template <class DataType>
linkList<DataType>::~linkList()
{
    node<DataType>* p;
    while(first != NULL){
        p = first;
        first = first->next;
        delete p;
    }
}
template <class DataType>
void linkList<DataType>::Delete()
{
                      node<int>* r=NULL;
                 r=first->next;
                 int n=r->data;
        		 while(r->next)
        		 {
        		 	node<int>* c=r->next;
        			if(n==r->next->data)
        		 	{
        				 r->next=(r->next)->next;
        				 delete c;
        			 }
        			 else
        			 {
        			 	n=(r->next)->data;
        			 	r=r->next;
        			 }
        		 }

}

template <class DataType>
void linkList<DataType>::show()
{
    node<DataType>* p = first->next;
    if(p == NULL) cout<<"Empty";
    else{
        while(p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    linkList<int> L;
    L.Delete();
    L.show();
    L.~linkList();
    return 0;
}


