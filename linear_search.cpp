#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

int linear_search(int arr[], int size, int key){
    for(int i=0;i<size;i++)
        if(arr[i]==key)
            return i;
    return -1;
}

main(){
    int arr[]={5,57,8,5,1,8,1,58,21,54,2,5,521,21};
    int size=sizeof(arr)/sizeof(arr[0]),n;

    cout<<"Array: ";
    print(arr,size);

    cout<<"\nEnter the number to be searched: ";
    cin>>n;
    int res= linear_search(arr,size,n);
    if(res!=-1)
        cout<<"Element Found at index: "<<res;
    else
        cout<<"Element Not-Found";
}