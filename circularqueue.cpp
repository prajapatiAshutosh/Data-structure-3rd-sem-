#include<iostream>
using namespace std;

class Node
{
  public:
  int value;
  Node *next;
  Node(int a)
  {value=a;next==NULL;}
};

class Queue
{
  public:
  Node *front,*back;
  int size;
  Queue()
  {front=NULL;back=NULL;size=0;}
  void enqueue(int a)
  {
    cout<<"Pushing "<<a<<" to the Circular Queue"<<endl;
    size++;
    Node *temp= new Node(a);
    if(front==NULL)
    {
      front =temp;
    }
    else back->next=temp;
    back=temp; // back=back->next
    back->next=front;
  }
  int dequeue()
  {
    if(front==NULL) {cout<<"The Circular Queue is empty"<<endl; return -1;}
    size--;
    int a;
    if(front==back)
    {
      a=front->value;
      delete front;
      front=back=NULL;
      cout<<"Popping the top value "<<a<<"from the Circular Queue"<<endl;
      return a;
    }
    Node *temp=front;
    a=temp->value;
    front=front->next;
    back->next=front;
    delete temp;
    cout<<"Popping the top value "<<a<<" from the Circular Queue"<<endl;
    return a;
  }
  void Show()
  {
    if(size==0) {cout<<"The Circular Queue is empty."<<endl;return;}
    cout<<"The Queue is:";
    Node *temp=front;
    while(temp->next!=front)
    {cout<<" "<<temp->value;temp=temp->next;}
    cout<<" "<<temp->value;
    cout<<endl;
  }

};

int main()
{
  Queue q;
  q.enqueue(3);q.enqueue(5);q.enqueue(2);
  q.enqueue(5);q.enqueue(6);
  q.Show();
  q.enqueue(7);q.dequeue();q.dequeue();
  q.Show();
}
