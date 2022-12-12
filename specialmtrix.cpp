#include<iostream>
using namespace std;

void diagonal_set(int i,int j,int x,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return;
	}
	if(i==j)
		arr[i-1]=x;
	else if(x!=0)
		cout<<"\nNon-diagonal elements must be zero\n";
}
int diagonal_get(int i,int j,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return -1;
	}
	if(i==j)
		return arr[i-1];
	else
		return 0; 
}

void lower_tri_set(int i,int j,int x,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return;
	}
	if(i>=j)
		arr[(i*(i-1)/2)+(j-1)]=x;
	else if(x!=0)
		cout<<"\nElements not in lower trianglr must be zero\n";
}
int lower_tri_get(int i,int j,int *arr, int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return -1;
	}
	if(i>=j)
		return arr[(i*(i-1)/2)+(j-1)];
	else
		return 0;
}

void upper_tri_set(int i,int j,int x,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return;
	}
	if(j>=i)
		arr[(j*(j-1)/2)+(i-1)]=x;
	else if(x!=0)
		cout<<"\nElements not in upper triangle must be zero\n";
}
int upper_tri_get(int i,int j,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return -1;
	}
	if(j>=i)
		return arr[(j*(j-1)/2)+(i-1)];
	else
		return 0;
}

void symmetric_set(int i,int j,int x,int *arr,int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return;
	}
	if(i<j)
	{
		int temp=i;
		i=j;
		j=temp;
	}
	arr[(i*(i-1)/2)+(j-1)]=x;
}
int symmetric_get(int i,int j,int *arr, int r)
{
	if(i<0 || j<0 || i>r || j>r)
	{
		cout<<"\nInvalid matrix index\n";
		return -1;
	}
	if(i<j)
	{
		int temp=i;
		i=j;
		j=temp;
	}
	return arr[(i*(i-1)/2)+(j-1)];
}

int main()
{
	int ch,i,j,x,r,c,a=1;
	int *d, *l, *u, *s;
	cout<<"\tSPECIAL MATRICES";
	cout<<endl<<"-----------------------------------------";
	do
	{
		cout<<endl<<"1. Diagonal matrix";
		cout<<endl<<"2. Lower triangular matrix";
		cout<<endl<<"3. Upper triangular matrix";
		cout<<endl<<"4. Symmetric matrix";
		cout<<endl<<"0. Exit";
		cout<<endl<<"Enter choice: ";
		cin>>ch;
		if(ch)
		{
			cout<<endl<<"No. of rows/columns in the matrix: ";
			cin>>r;
			if(ch==1)
				d=new int[r];
			else if(ch==2)
				l=new int[r*(r+1)/2];
			else if(ch==3)
				u=new int[r*(r+1)/2];
			else if(ch==4)
				s=new int[r*(r+1)/2];
		}
		while(ch && a)
		{
			cout<<endl<<"1. Set";
			cout<<endl<<"2. Get";
			cout<<endl<<"0. Exit";	
			cout<<endl<<"Enter choice: ";
			cin>>a;
			if(ch==1)
			{
				if(a==1)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					cout<<"Enter the value to be set: ";
					cin>>x;
					diagonal_set(i,j,x,d,r);
				}
				else if(a==2)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					x=diagonal_get(i,j,d,r);
					if(x!=-1)
						cout<<x<<endl;
				}
			}
			else if(ch==2)
			{
				if(a==1)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					cout<<"Enter the value to be set: ";
					cin>>x;
					lower_tri_set(i,j,x,l,r);
				}
				else if(a==2)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					x=lower_tri_get(i,j,l,r);
					if(x!=-1)
						cout<<x<<endl;
				}
			}
			else if(ch==3)
			{
				if(a==1)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					cout<<"Enter the value to be set: ";
					cin>>x;
					upper_tri_set(i,j,x,u,r);
				}
				else if(a==2)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					x=upper_tri_get(i,j,u,r);
					if(x!=-1)
						cout<<x<<endl;
				}
			}
			else if(ch==4)
			{
				if(a==1)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					cout<<"Enter the value to be set: ";
					cin>>x;
					symmetric_set(i,j,x,s,r);
				}
				else if(a==2)
				{
					cout<<"Enter the index:";
					cout<<"\nRow: ";
					cin>>i;
					cout<<"Column: ";
					cin>>j;
					x=symmetric_get(i,j,s,r);
					if(x!=-1)
						cout<<x<<endl;
				}
			}
		}
		a=1;
	}while(ch);

	return 1;
}