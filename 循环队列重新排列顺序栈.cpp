#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> seqStack;
queue<int> cirQueue;
int n;
void init(int len)
{
    for(int i=0;i<2*len;++i){
        int elem;
        cin>>elem;
        seqStack.push(elem);
    }
}
void exchange()
{
  while(!seqStack.empty())
     {
         cirQueue.push(seqStack.top());
         seqStack.pop();
     }
         int i=cirQueue.size();
         while(i>0)/*大于零*/
         {
             if(i%2==0)
             {
                 cirQueue.push(cirQueue.front());
                 cirQueue.pop();
             }
             else
             {
                 seqStack.push(cirQueue.front());
                 cirQueue.pop();
             }
             i--;
         }
         i=cirQueue.size();
         while(!seqStack.empty())
         {
             cirQueue.push(seqStack.top());
             seqStack.pop();
         }
         while(i>0)
         {
             seqStack.push(cirQueue.front());
             cirQueue.pop();
             i--;
         }
          while(!seqStack.empty())
         {
             cirQueue.push(seqStack.top());
             seqStack.pop();
         }
         i=cirQueue.size();
         while(i>0)
         {
             seqStack.push(cirQueue.front());
             cirQueue.pop();
             i--;
         }

}
void printStack()
{
    while(!seqStack.empty()){
        cout<<seqStack.top()<<" ";
        seqStack.pop();
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    init(n);
    exchange();
    printStack();
    return 0;
}


