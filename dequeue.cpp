#include<iostream>
using namespace std;

class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
			return;
		}
		friend class DLL;
		friend class dequeue;
};

class DLL
{
	node* head;
	node* tail;
	
	public:
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
			return;
		}
		~DLL(){
			node* curr=head->next;
        	node* temp;
        	for(;curr!=tail;curr=curr->next)
        	{
        		temp=curr;
        		delete curr;
			}
			head->next = tail;
			tail->next = head;
		}
		void add(node* ptr,int a);
		void insertathead(int a);
		void insertattail(int a);
		int remove(node* ptr);
		int removefromhead();
		int removefromtail();
		void print();
		friend class dequeue;
};

void DLL::add(node* ptr,int a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertathead(int a)
{
	add(head->next,a);
	return;
}

void DLL::insertattail(int a)
{
	add(tail,a);
	return;
}

int DLL::remove(node* ptr)
{
	node* current=ptr->prev;
	ptr->next->prev=current;
	current->next=ptr->next;
	int temp=ptr->val;
	delete ptr;
	return temp;
}

int DLL::removefromhead()
{
	if(head->next!=tail)
	{
		return remove(head->next);
	}
	return -1;
	
}

int DLL::removefromtail()
{
	if(head->next!=tail)
	{
		return remove(tail->prev);
	}
	return -1;
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	return;
}

class dequeue
{
	DLL D;
	
	public:
		dequeue(){
		}
		void enqueue_front(int a);
		void enqueue_rear(int a);
		int dequeue_front();
		int dequeue_rear();
		bool isempty();
		int front_el();
		int rear_el();
	    void clear();
	    void print();
};

void dequeue::enqueue_front(int a)
{
	D.insertathead(a);
}

void dequeue::enqueue_rear(int a)
{
	D.insertattail(a);
}

int dequeue::dequeue_front()
{
	return D.removefromhead();
}

int dequeue::dequeue_rear()
{
	return D.removefromtail();
}

bool dequeue::isempty()
{
	return(D.head->next==D.tail);
}

int dequeue::front_el()
{
	if(isempty())
	{
		return -1;
	}
	return D.head->val;	
}

int dequeue::rear_el()
{
	if(isempty())
	{
		return -1;
	}
	return D.tail->val;
}

void dequeue::clear()
{
	D.~DLL();
}

void dequeue::print()
{
	D.print();
}

int main()
{
	dequeue d;
	d.enqueue_front(4);
	d.enqueue_rear(8);
	d.enqueue_rear(1);
	d.enqueue_front(9);
	d.print();
    cout<<d.dequeue_front()<<endl;
	cout<<d.dequeue_rear()<<endl;
	cout<<d.front_el()<<endl;
	d.print();
	d.clear();
	cout<<"Checking Empty: "<<d.isempty();
}