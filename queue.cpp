#include<iostream>
using namespace std;

class queue
{
	int *ar;
	int front;
	int rear;
	int n;
	
	public:
		queue();
		void enqueue(int n);
		int dequeue();
		bool isempty();
		bool isfull();
		int size();
		int frontel();
		void clear();	
};

queue::queue()
{
    cout<<"Enter the size of queue: ";
	cin>>n;
	ar = new int[n];
	front = -1;
	rear = -1;
	return;	
}

void queue::enqueue(int a)
{
	if(isempty())
	{
		front=0;
		rear=0;
	}
	else
	{
		if(isfull())
		{
			cout<<"overflow!!\n";
			return;
		}
		else
		{
			rear = (++rear)%n;
		}
	}
	ar[rear]=a;
	cout<<a<<" Added to the queue\n";
}

int queue::dequeue()
{
	int temp;
	if(isempty())
	{
		cout<<"underflow!!\n";
		return -1;
	}
	else
	{
		temp = ar[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (++front)%n;
		}
		return temp;
	}
}

bool queue::isempty()
{
	return(front == -1 && rear == -1);
}

bool queue::isfull()
{
	if(size() == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int queue::size()
{
	if(isempty())
	{
		return 0;
	}
	if(rear<front)
	{
		return (n-front+rear+1);
	}
	else
	{
	    return (rear-front+1);	
	}
}

int queue::frontel()
{
	if(isempty())
	{
		return -1;
	}
	else
	{
		return ar[front];
	}
}

void queue::clear()
{
	front = -1;
	rear = -1;
	return;
}

int main()
{
	queue q1;
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(3);
	q1.enqueue(1);
	q1.enqueue(7);
	q1.enqueue(9);
	cout<<"checking full: "<<q1.isfull()<<endl;
	cout<<"Front element: "<<q1.frontel()<<endl;
	cout<<"Dequeue 2 times: "<<endl;
	cout<<q1.dequeue()<<endl;
	cout<<q1.dequeue()<<endl;
	cout<<"Front element: "<<q1.frontel()<<endl;
	cout<<"Size of queue: "<<q1.size()<<endl;
	cout<<"Clear operation on queue"<<endl;
	q1.clear();
	cout<<"Size of queue: "<<q1.size()<<endl;
	cout<<"checking empty: "<<q1.isfull()<<endl;
	cout<<"Performing Dequeue"<<endl;
	cout<<q1.dequeue()<<endl;		
	return 0;	
}