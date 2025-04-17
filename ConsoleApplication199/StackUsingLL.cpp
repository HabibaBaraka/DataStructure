// manualStackUsingLL.cpp : 
#include <iostream>
#include <cassert>
using namespace std;
const int MAX_SIZE = 100;
template<class t>
// nn new node 
// dlt delete
class Stack
{
private:
struct Node{
t item;
Node*next;
};
Node*top=nullptr;
public:
void push(t val){
  Node*nn=new Node;
  nn->item=val;
  nn->next=top;
  top=nn;
}
void pop(){
  if(empty()){
    cout<<"Stack is empty\n";
  }
  Node*nTop=top->next;
  top->next=nullptr;
  delete top;
  top=nTop;
}
void pop(t&oldTop){
  if(empty()){
    cout<<"Stack is empty\n";
  }
  Node*nTop=top->next;
  oldTop=top->item;
  top->next=nullptr;
  delete top;
  top=nTop;
}
void print (){
  Node*cur=top;
  cout<<'[';
  while(cur){
    cout<<cur->item<<" ";
    cur=cur->next;
  }
  cout<<"]\n";
  
}
bool empty(){
    return !top;
  }
void getTop(t&Top){
  Top=top->item;
}
void pop2(){
  Node*temp=top;
  top=top->next;
  temp->next=NULL;
  delete temp;
}

};

int main()
{
Stack<int> s;
s.push(5);
cout<<s.empty();
}
