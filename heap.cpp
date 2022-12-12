#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Heap{
    vector<int> v;

    public:
    Heap(int default_size=10){
     v.reserve(default_size);
     v.push_back(-1);

    }
     void heapify(int i){
        int l=2*i;
        int r=2*i+1;
        int min=i;
        if(l<v.size() and v[l]<v[min])
          min=l;
        if(r<v.size() and v[r]<v[min])
          min=r;
         if(min!=i){
          swap(v[i],v[min]);
          heapify(min);
         }
            
     }
     void push(int data){
          v.push_back(data);
          int indx=v.size()-1;
          int parent=indx/2;
         while(indx>1 and v[indx]<v[parent]){
          swap(v[indx],v[parent]);
          indx=parent;
          parent=parent/2;

         }
     }
     int getmin(){
          if(v.empty())
            return 0;
          return v[1];
     }
      int search(int ele){
          for(int i=1;i<v.size();i++){
               if(v[i]==ele)
                 return i;
          }
          return -1;
      }
      void remove(int ele){
          int indx=search(ele);
          v[indx]=v[v.size()-1];
          v.pop_back();
          heapify(indx);
      }
};

int main(){
    Heap mH; int choice; int flag = 1;   int x;
    cout << "----- Menu -----\n"
         << "1.Enter priority\n"
         << "2.Extract data\n"
         << "3.Get Top priority.\n"
         << "4.Quit\n";
    while(flag){
        cout << "Enter your choice : ";
        cin >> choice;
        
        if(choice==1)
        {
        	cout << "Enter data : ";
            cin >> x;
            mH.push(x);
		}
		else if(choice==2)
		{
			cout << "Enter data to be extracted : ";
            cin >> x;
            mH.remove(x);
		}
		else if(choice==3)
		{
			cout << "Top priority : " <<  mH.getmin() << endl;
		}
		else
		{
			flag=0;
		}
        
    }
    return 0;
}

