#include <iostream>


using namespace std;
template <typename T>

class Node
{
public:
     Node<T> *next;
     T data;
    Node<T>(T val, Node<T> *ptr = NULL)
    {
        data = val;
        next = ptr;
    }
    template<typename U>
    friend class list;
};
 
 template<typename T>
class list
{
    Node<T> *head;

public:
    list()
    {
        head = NULL;
    }
    bool isempty()
    {
        return head==NULL;
    }
    void addhead(T data)
    {
        head = new Node(data, head);
    }
    void dispaly()
    {
        Node<T> *ptr = head;
        while (ptr)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "NULL";
    }
    void removehead()
    {
        Node<T> *ptr = head;
        // int val=ptr->data;
        cout << "\nThe deleted data is : " << ptr->data << endl;
        head = head->next;
        delete ptr;
    }
    void insertafter(T val, T ele)
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp!= NULL)
            {
                if (temp->data == ele)
                {
                    Node<T> *n = new Node(val, temp->next);
                    temp->next=n;
                    
                
                }
                temp = temp->next;
            }
        }
        else
            addhead(val);
    }
    int search(T val)
    {
        int count = 0;
        Node<T> *temp = head;
        if (head)
        {
            while (temp->next != NULL)
            {
                if (temp->data == val)
                {
                    return count;
                }
                count++;
                temp = temp->next;
            }
        }
    }
    void addend(int val)
    {
        if (head)
        {
            Node<T> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node<T> *n = new Node(val);
            temp->next = n;
        }
        else
            addhead(val);
    }
    void removeend()
    {
        if (head)
        {
            if (head->next != NULL)
            {
                Node<T> *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }

            else
            {
                delete head;
                head = 0;
            }
        }
    }
    void sort1()
    {
        Node<T> *temp = head;
        Node<T> *temp1 = head->next;
        if (head)
        {
            while (temp->next!= NULL)
            {
                

                while (temp1!= NULL)
                {
                    if (temp->data > temp1->data)
                    {
                        swap(temp->data, temp1->data);
                    }
                    else
                    {
                        temp1 = temp1->next;
                    }
                }

                temp = temp->next;
                temp1 = temp->next;
            }
        }
    }
    void deletefromend(){
        if(head==NULL)
         return ;
        if(head->next==NULL){
         delete head;
        //   return ;
        }
           Node<T>* secondlast=head;
           while(secondlast->next->next!=NULL){
            secondlast=secondlast->next;
           }
           delete secondlast->next;
           secondlast->next=NULL;
           return;
    }
    list join(list l){
        Node<T>* temp=l.head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=this->head;
        // l.dispaly();
        return l;
    }
    void insertafterindex(int x,T val ){
        Node<T>* temp=head;
        for(int i=0;i<x;i++){
            temp=temp->next;
        }
        insertafter(val,temp->data);
    }
  Node<T>* HEAD(){
    return head;
  }
  int lengthoflist(){
    int count=0;
    Node<T>*temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
  }
  void reverse(){
    Node<T> *c=head;
    Node<T> *p=NULL;
    Node<T> *n;

    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
  }
};
template<typename T>
T palindrome(list<char> s){
    int count=s.lengthoflist();
    char* arr=new char[count];
    int i=0,flag;
    Node<char>* temp=s.HEAD();
    while(temp){
      arr[i]=temp->data;
      temp=temp->next;
      i++;
    }
    for(int i=0;i<count;i++){
        if(arr[i]==arr[count-i-1]){
            flag=0;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==0){
 cout<<"List is palindrome ";

    }
    else
    cout<<"Not Palindrome";
}

int main()
{
   cout<<"==========MENU==========\n";
   cout<<" 1.Insert  the value at head\n";
   cout<<" 2. Insert after certain value\n";
   cout<<" 3.Remove from Head\n";
   cout<<" 4.Search the element\n";
   cout<<" 5.Add at the end\n";
   cout<<" 6.Remove from end\n";
   cout<<" 7.Sort the linked list\n";
   cout<<" 8.Join two linked list\n";
   cout<<" 9.Reverse the linked list\n";
   cout<<" 10.Check Palindrome Linked list";

   list<float> l;
   int choice;
   cout<<"\n Enter the choice : ";
   cin>>choice;
   cout<<endl;
   switch(choice){
    case 1:do{
           cout<<"\nEnter the value you want to enter : ";
           int x;
           cin>>x;
           l.addhead(x);
         cout<<"\nDo you want to Insert more(Y/N) : ";
         char z;
         cin>>z;
           
    }while(z=='Y' or z=='y');
           break;

   }
   

}






//     list <float> l;
    
//     l.addhead(1);
//     l.addhead(1);
//     l.addhead(2);
//     // l.addhead(59.87);
//     l.addhead(1);
//     // l.addhead(41);
//     // l.addhead(10);
//     // l.insertafter(12, 59);
//     // l.removehead();
//     // l.dispaly();
//     // l.reverse();
//     // cout<<endl;
//     // l.dispaly();
//     // cout << "\nThe number is at position : " << l.search(12) << endl;
//     // l.addend(13);
//     // l.dispaly();
//     // cout << endl;
//     // l.removeend();
//     // l.dispaly();
//     // l.sort1();
//     // cout << endl;
//     // l.deletefromend();
//     // l.dispaly();
//     list<float> l2;
//     l2.addhead(9);
//     l2.addhead(19);
//     l2.addhead(79);
//     l2.addhead(99);
//     cout<<endl;
//     l2.dispaly();
//     cout<<endl;
//     list<float> l3;
//     l3=l.join(l2);

//     l3.dispaly();
//     l3.insertafterindex(2,0.98);
//     cout<<endl;
//     l3.dispaly();
//     list<char> s;
//     s.addhead('1');
//     s.addhead('1');
//     s.addhead('2');
//     s.addhead('1');
//     // s.addhead('a');
//     cout<<endl;
//    palindrome<void>(s);
//     cout<<endl;
//       s.dispaly();
//     //   Node<char>* m=s.HEAD();
//     //   cout<<endl;
//     //   cout<<m->data;
//     // l.sort1();
//     // l.dispaly();

//     return 0;