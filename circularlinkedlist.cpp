#include<iostream>
using namespace std;
class node{
    int data ;
    node *next;
    public:
      node(){
        data=0;
        next=NULL;
      }
      friend class clist;
};

class clist{
node* cursor;

public:
clist(){
    cursor=NULL;
}
bool isempty(){
  return cursor==NULL;
}
int back(){
  return cursor->data;
}
int front(){
  return cursor->next->data;
}
void advanced(){
  cursor=cursor->next;
}
void add(int val){
  node* n=new node;
  n->data=val;
  if(cursor==NULL){
    n->next=n;
    cursor=n;
  }
  else{
    n->next=cursor->next;
    cursor->next=n;
  }
}
void addback(int val){
  node *n=new node;
  node *temp=cursor;
  n->data=val;
  n->next=cursor->next;
  temp->next=n;
  cursor=n;
}
void remove(int ele){
  node* n=cursor->next;
  if(n==cursor){
    cursor=NULL;
  }
  else{
    while(n->next->data!=ele){
      n=n->next;
    }
     node* temp=n->next;
     n->next=n->next->next;
     delete temp;
     temp=NULL;
  }
}
void removehead(){
     node* temp=cursor;
     remove(temp->next->data);
}
void removeend(){
  node *temp=cursor->next;
  while(temp->next!=cursor){
    temp=temp->next;
  }
  remove(temp->next->data);
  cursor=temp;
}
void display(){
  node* n=cursor->next;
  
 while(n->next!=cursor->next){
    cout<<n->data<<"->";
    n=n->next;
  } 
  if(n==cursor){
    cout<<n->data;
  }
  
}
void insertbetween(int ele,int val){
  node *temp=cursor->next;
  while(temp->next->data!=ele){
      temp=temp->next;
  }
  node *n =new node();
  n->data=val;
  n->next=temp->next;
  temp->next=n;

}
};
int main(){
  clist c;
  c.add(10);
  c.add(20);
  c.add(30);
  c.add(40);
  c.add(50);
  c.addback(60);
  
  c.display();
  cout<<"\n"<<c.front();
  cout<<"\n"<<c.back()<<"\n";
  // c.remove();
  c.insertbetween(20,9);
  c.display();
  c.remove(30);
  c.removehead();
  cout<<endl;
  c.display();
  cout<<endl;
  c.removeend();
  c.display();

}

