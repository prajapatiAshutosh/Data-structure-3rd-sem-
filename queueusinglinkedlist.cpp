#include<iostream>
using namespace std;

class node
{
	int val;
	node* next;
	
	public:
		node(int a=0,node* ptr=0)
		{
			val=a;
			next=ptr;
		}
		friend class CLL;
		friend class queue;
};

class CLL
{
	node* tail;
	
	public:
		CLL(node* ptr=0)
		{
			tail=ptr;
		}
		~CLL()
		{
			node* curr=tail->next;
        	node* temp;
        	do{
        		temp = curr;
				delete temp;
				curr = curr->next;        		
			}while(curr!=tail->next);
			tail = 0;			
		}
		void insertatback(int a);
		int removefromfront();
		void print();
		friend class queue;
};

void CLL::insertatback(int a)
{
	if(tail)
	{
		tail = tail->next=new node(a,tail->next);
		return;
	}
	tail = new node(a,0);
	tail->next=tail;
}

int CLL::removefromfront()
{
	if(tail)
	{
		node* curr=tail->next;
		int a = curr->val;
		if(curr==tail)
		{
			tail=0;			
		}
		else
		{
		    tail->next=curr->next;
		}
		delete curr;
		return a;
	}
	return -1;	
}

void CLL::print()
{
	if(tail)	
	{
		node* curr = tail->next;
		do{
			cout<<curr->val<<" ";
			curr=curr->next;
		}
		while(curr!=tail->next);
		cout<<endl;
	}
	return;
}

class queue
{
	CLL c;
	
	public:
		queue()
		{
			c.tail=0;			
		}
		void enqueue(int a);
		int dequeue();
		int frontel();
		bool isempty();
		void clear();
		void print();	
};

void queue::enqueue(int a)
{
	c.insertatback(a);
}

int queue::dequeue()
{
	return c.removefromfront();
}

int queue::frontel()
{
	return c.tail->next->val;
}

bool queue::isempty()
{
	return !c.tail;
}

void queue::clear()
{
	c.~CLL();
}

void queue::print()
{
	c.print();
}

int main()
{
	queue q;
	q.enqueue(5);
	q.enqueue(7);
	q.enqueue(3);
	q.enqueue(9);
	q.print();
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.frontel()<<endl;
	q.print();
	q.clear();
	cout<<"Checking empty "<<q.isempty();
}