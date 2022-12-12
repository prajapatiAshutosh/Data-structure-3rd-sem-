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
			return;
		}
		friend class SLL;
		friend class stack;
};

class SLL
{
	node* head;
	
	public:
		SLL(node* ptr = 0)
		{
	        head = ptr;
	        return;
        }
        ~SLL()
        {
        	node* curr=head;
        	node* temp;
        	for(;curr!=0;curr=curr->next)
        	{
        		temp=curr;
        		delete curr;
			}
			head = 0;
		}
		void insertathead(int a);
		int removefromhead();
		void print();
		friend class stack;
};

void SLL::insertathead(int a)
{
	head = new node(a,head);
	return;
}

int SLL::removefromhead()
{
	if(head)
	{
		node* current = head;
		head = head->next;
		int a=current->val;
		delete current;
		return a;
	}
	else
	{
		return -1;
	}
}

void SLL::print()
{
	if(head)
	{
		node* current=head;
		for(;current;current=current->next)
		{
			cout<<current->val<<" ";
		}
		cout<<endl;
	}
	return;
}

class stack{
	
	SLL s;
	
public:
	
	stack(){
		s.head=0;		
	}
	void push(int a);
	int pop();
	bool isempty();
	int topel();
	void clear();
	void print();
};

void stack::push(int a)
{
	s.insertathead(a);
}

int stack::pop()
{
	return s.removefromhead();
}

bool stack::isempty()
{
	return !s.head;
}

int stack::topel()
{
	if(isempty())
	{
		return -1;
	}
	return s.head->val;
}

void stack::clear()
{
	s.~SLL();
}

void stack::print()
{
	s.print();
}

int main()
{
	stack s;
	s.push(5);
	s.push(7);
	s.push(6);
	s.push(9);
	cout<<s.pop()<<endl;
	s.print();
	cout<<s.isempty();
	cout<<endl<<s.topel();
	s.clear();
	s.print();
	
		
}