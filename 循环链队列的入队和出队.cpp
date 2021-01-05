#include <iostream>
using namespace std;

template <class DataType>
struct node{
    DataType data;
    node<DataType>* next;
};

template <class DataType>
class cirLinkQueue{
public:
    cirLinkQueue();
    cirLinkQueue(DataType a[],int n);
    void enQueue(DataType elem);
    bool deQueue();
    void printQueue();
private:
    node<DataType>* rear;
};

template <class DataType>
cirLinkQueue<DataType>::cirLinkQueue()
{
    rear = NULL;
}

template <class DataType>
cirLinkQueue<DataType>::cirLinkQueue(DataType a[],int n)
{
    if(n == 1){
        rear = new node<DataType>;
        rear->data = a[0];
        rear->next = rear;
    }
    else{
        rear = new node<DataType>;
        rear->data = a[0];
        rear->next = rear;
        for(int i=1;i<n;++i){
            node<DataType>* s = new node<DataType>;
            s->data = a[i];
            s->next = rear->next;
            rear->next = s;
            rear = s;
        }
    }
}

template <class DataType>
void cirLinkQueue<DataType>::enQueue(DataType elem)
{
             if(rear==NULL)
                {
                    rear=new node<int>;
                    rear->next=rear;
                    rear->data=elem;
                }
                else
                {
                    node<int>*p=new node<int>;
                    p->data=elem;
                    p->next=rear->next;
                    rear->next=p;
                    rear=p;
                }

}

template <class DataType>
bool cirLinkQueue<DataType>::deQueue()
{
         node<int>*front=rear->next;
             node<int>*p;
              p=front;
              if(p==rear)
              {
                  rear =NULL;
                  return 0;
              }
              rear->next=p->next;
              delete p;
              return 1;

}

template <class DataType>
void cirLinkQueue<DataType>::printQueue()
{
    if(rear == NULL)
        cout<<"Empty"<<endl;
    else{
        node<DataType>* p = rear->next;
        while(p != rear){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<p->data<<endl;
    }
}
int main()
{
    cirLinkQueue<int> Q;
    int m,n;
    cin>>m;
    while(m--){
        int elem;
        cin>>elem;
        Q.enQueue(elem);
    }
    cin>>n;
    while(n--){
        bool res = Q.deQueue();
        if(!res) break;
    }
    Q.printQueue();
    return 0;
}


