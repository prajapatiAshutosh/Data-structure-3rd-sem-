#include<iostream>
using namespace std;
template <typename T>
class Sorting
{		T n;
		T *ar;
	public:
		Sorting(T arr[], int s);
		void input();
		void display();
		void selectionSort();
		void bubbleSort();
		void insertionSort();
};

template <typename T>
Sorting<T>::Sorting(T arr[], int s) 
{
	ar= new T[s];
	n= s;
	for(int i=0;i<n;i++)
	ar[i]= arr[i];
	
}

template <typename T>
void Sorting<T>::input() 
{
cout<<"\nENTER THE DATA YOU WANT TO SORT :";
	for(int i = 0; i<n; i++)	
	{
		cin>>ar[i];
	}
}
template <typename T>
void Sorting<T>::display() 
{
   for(int i = 0; i<n; i++)
   cout << ar[i] << " ";
   cout << endl;
}

template <typename T>
void Sorting<T>::selectionSort() 
{
T temp;
for(int i=0;i<n;i++)
{
  for(int j=i+1;j<n;j++)
  {
   if(ar[i]>ar[j])
   {
    temp=ar[i];
    ar[i]=ar[j];
    ar[j]=temp;
   }
  }
}
}

template <typename T>
void Sorting<T>:: bubbleSort() 
{	
T temp;
for(int i=0;i<n;i++)
{
  for(int j=0;j<n-i-1;j++)
  {
   if(ar[j]>ar[j+1])
   {
    temp=ar[j];
    ar[j]=ar[j+1];
    ar[j+1]=temp;
   }
  }
}
} 

template <typename T>
void Sorting<T>:: insertionSort()
{
T key;
int i, j;  
    for (i = 1; i < n; i++) 
    {  
        key = ar[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && ar[j] > key) 
        {  
            ar[j + 1] = ar[j];  
            j = j - 1;  
        }  
        ar[j + 1] = key;  
    }  
}

int main()
{
	int choice, n;
	int*arr=NULL;
	cout<<"\n \t\t\t\t\tSORTING TECHNIQUES\n\n";
	cout<<"\nEnter the size of the Array:  ";
  	cin>>n;
  	arr= new int[n];
	Sorting<int>st(arr,n) ;
    
    do
    {	cout<<"*****Options*****"<<endl;
        cout<<"1 - INSERTION SORTING"<<endl;
        cout<<"2 - BUBBLE SORTING"<<endl;
        cout<<"3 - SELECTION SORTING "<<endl;
        cout<<"4 - Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
         
        switch(choice)
		{
		    case 1: 
					cout<<"\n*********Insertion sort execution*********\n"<<endl;
          st.input();
          cout << "\nArray before Sorting: "<<endl;
            st.display();
          st.insertionSort();
            cout << "\nArray after Insertion Sorting:\n ";
            st.display();
            cout<<endl;

		    break;
                 
            case 2:
                	cout<<"\n*********Bubble sort execution*********\n"<<endl;
					st.input();
					cout << "\nArray before Sorting: "<<endl;
   					st.display();
					st.bubbleSort();
   					cout << "\nArray after Bubble Sorting:\n ";
   					st.display();
   					cout<<endl;

            break;
             
            case 3:
                  cout<<"\n*********Selection sort execution*********\n"<<endl;
                st.input();
          cout << "\nArray before Sorting: "<<endl;
            st.display();
              st.selectionSort();
            cout << "\nArray after Selection Sorting: "<<endl;
            st.display();
            cout<<endl;

            break;
            
            case 4:
				
				break;
            
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
 
    return 0;
} 
