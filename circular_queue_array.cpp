#include<iostream>
using namespace std;

class queue{
    public:
        int front, rear, size;
        int *arr;
        queue(int s){
            size = s; 
            arr = new int[s];
            front = -1;
            rear = -1;
        }

        bool isFull(){
            return ((rear+1)%size==front);
        }
        bool isEmpty(){
            return (rear==-1);
        }

        bool enqueue(int x){
            if(isFull())
                return false;
            else{
                if(isEmpty())
                    front=0;
                rear = (rear+1)%size;
                arr[rear] = x;
                return true;
            }
        }

        int dequeue(){
            if(isEmpty())
                return -1;
            int val = arr[front];
            
            if(front == rear)
                rear = -1;
            else
                front = (front+1)%size;
            return val;
        }

        int Front(){
            return arr[front];
        }
        
        int Rear(){
            return arr[rear];
        }

    void display(){
        int temp=front;
        if(isEmpty()){
            cout<<"Empty Queue\n";
            return;
        }
        cout<<"Queue: ";
        while(true){
            cout<<arr[temp]<<" ";
            temp = (temp+1)%size;
            if(temp==(rear+1)%size)
                break;
        }
        cout<<endl;
    }
};

main(){ 
    queue q(5);
    int choice,ele;
    while(true){
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Is Full\n6. Is Empty\n7. Exit\nChoice> ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter element to enqueue: ";
                    cin>>ele;
                    if(q.enqueue(ele))
                        cout<<ele<<" enqueued successfully\n";
                    else
                        cout<<"Queue Overflow\n";
                    break;
            case 2: ele = q.dequeue();
                    if(ele==-1)
                        cout<<"Queue Underflow\n";
                    else
                        cout<<"Dequeued element: "<<ele<<endl;
                    break;
            case 3: q.display();
                    break;
            case 4: cout<<"Top element: "<<q.Front()<<endl;
                    break;
            case 5: if(q.isFull())
                        cout<<"Queue is full\n";
                    else
                        cout<<"Queue is not full\n";
                    break;
            case 6: if(q.isEmpty())
                        cout<<"Queue is empty\n";
                    else
                        cout<<"Queue is not empty\n";
                    break;
            case 7: break;
            default: cout<<"Invalid choice\n";
        }
    }
}