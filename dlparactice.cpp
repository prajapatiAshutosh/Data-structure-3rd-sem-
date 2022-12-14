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
    if(head->next==NULL && head->prev==NULL){
       delete head;
       head=NULL;
    }
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
  int flag=1;
  int choice;
  
  // cout << l.isempty() << endl;
  cout << "----- Menu -----\n"
         << "1.Enter the data at the head\n"
         << "2.Remove data from head\n"
         << "3.Remove from tail.\n"
         << "4.Enter The data at the back\n"
         << "5.Reverse the linked list\n"
         << "6..Remove data \n"
         << "7.Add Data in between\n"
         << "8.Delete Alternative\n"
         << "9.Display\n"
         << "10.quit\n";
    while(flag){
        cout << "Enter your choice : ";
        cin >> choice;
        
        if(choice==1)
        {
        	cout << "Enter data : ";
          int x;
            cin >> x;
            l.addhead(x);
		}
		else if(choice==2)
		{
			cout << "Removed data from head  \n";
            l.removehead();
           
		}
		else if(choice==3)
		{
			cout << "Remove data from tail: \n";
            l.removetail();
		}
     else if(choice==4){
      cout<<"Enter the data at the back : ";
      int x;
         cin>>x;
         l.addback(x);
     }
     else if(choice==5){
      cout<<"Reverse The string: ";
        l.display();
     }
     else if(choice==6){
      cout<<"Enter the data you want to remove :";
      int x;
      cin>>x;
      l.remove(60);
     }
     else if(choice==7){
      cout<<"Enter the number after which you want to add data: ";
      int x;
      cin>>x;
      cout<<"Enter the number you want to enter : ";
      int y;
      cin>>y;
      l.addbetween(y,x);
     }
     else if(choice==8){
      cout<<"Delete Alternative \n";
      deleteAlt(l);
        
     }
     else if(choice==9){
      if(l.isempty())
        cout<<"No data :\n";
       else 
       l.display();
     }
		else if(choice==10)
		{
			flag=0;
		}
        
    }
  
}
