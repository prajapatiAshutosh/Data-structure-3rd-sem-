 #include <iostream>
using namespace std;

class node
{
  

public:
int data;
  node *next;
  node *prev;
  node()
  {
    data = 0;
    next = prev = NULL;
  }
  friend class dl;
};
class dl
{
  

public:
node *head;
  node *tail;
  dl()
  {
    head = NULL;
    tail = NULL;
  }
  bool isempty()
  {
    return head==NULL;
  }
  void addhead(int val)
  {
    if (isempty())
    {
      node *n = new node();
      n->data = val;
      head = tail = n;
    }
    else
    {
      node *n = new node();
      n->data = val;
      head->prev = n;
      n->next = head;
      head = n;
    }
  }
  void addback(int val)
  {
    if (isempty())
    {
      addhead(val);
    }
    else
    {
      node *n = new node();
      n->data = val;
      tail->next = n;
      n->prev = tail;
      tail = n;
    }
  }

  void display()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << "<=>";
      temp = temp->next;
    }
    cout << "NULL";
    cout << endl;

    //  node *temp2=tail;
    // while(temp2!=NULL){
    //     cout<<temp2->data<<"<=>";
    //     temp2=temp2->prev;
    // }
    // cout<<"NULL";
  }
  void removehead()
  {
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    temp = NULL;
  }
  void removetail()
  {
    node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
    temp = NULL;
  }
  void remove(int val)
  {
    node *temp = head;
    while (temp!= NULL)
    {
      if (head->data == val)
      {
       removehead();
       break;
      }
      else if (temp->data == val)
      {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        temp = 0;
        break;
      }
      else if (tail->data == val)
      {
        removetail();
      }
      else
        temp = temp->next;
    }
  }
  
  
  void addbetween(int val, int ele){
     node* temp=head;
     if(isempty()){
        addhead(val);
     }
     else{
     while(temp->data!=ele){
      temp=temp->next;
     }
     node* n=new node();
     n->data=val;
     n->next=temp->next;
     temp->next->prev=n;
     temp->next=n;
     n->prev=temp;

     }
  }
  void reverse()
{
    node* temp = NULL;
    node* current = head;
 
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    if (temp != NULL)
        head = temp->prev;
}

};
void deleteAlt(dl l) 
{ 
    if (l.head == NULL) 
        return; 
  
    node *prev = l.head; 
    node *node1 = l.head->next; 
  
    while (prev != NULL && node1 != NULL) 
    { 
        prev->next = node1->next; 
        delete(node1); 
      
        prev = prev->next; 
        if (prev != NULL) 
            node1 = prev->next; 
    } 
} 

int main()
{
  dl l;
  cout << l.isempty() << endl;
  
  l.addhead(1);
  l.addhead(2);
  l.addhead(3);
  l.addhead(4);
  l.addhead(5);
  l.addback(0);
  // l.display();
  // cout << endl;
  // l.removehead();
  // l.display();
  // cout << endl;
  // l.removetail();
  // l.display();
  // l.remove(60);
  // l.display();
  // l.reverse();
  // l.addbetween(67,60);

  l.display();
  cout<<endl;
  // l.swapnode(40,80);
//   l.swapnode(0,4);
//   l.swapnode(0,4);
  //  deleteAlt(l);
  l.reverse();
  l.display();
}