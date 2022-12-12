#include<iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void sort(int arr[], int size){
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(arr[i]>arr[j])
                    swap(arr[i],arr[j]);
}

int binary_search(int arr[], int size, int key){
    int low=0,high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

main(){
    int arr[]={5,57,8,5,1,8,1,58,21,54,2,5,521,21};
    int size=sizeof(arr)/sizeof(arr[0]),n;

    cout<<"Array: ";
    print(arr,size);
    cout<<"Sorted Array: ";
    sort(arr,size);
    print(arr,size);
    cout<<"Enter the number to be searched: ";
    cin>>n;
    int res= binary_search(arr,size,n);
    if(res!=-1)
        cout<<"Element Found at index: "<<res;
    else
        cout<<"Element Not-Found";
}