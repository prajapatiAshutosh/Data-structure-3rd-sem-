#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class node{

public:
int key;
node *left ,*right;

node(int data){
    key=data;
    left=right=NULL;
}
   
};
class BST{
    public:
    node* root;
    BST(){
        root=NULL;
    }
    void insert(int value){
        node *p=root;
        node* prev=NULL;
        
        while(p!=NULL){
            prev=p;
            if(value<p->key)
               p=p->left;
             else
              p=p->right;  
        }
        if(root==NULL)
         root=new node(value);

         else if(value<prev->key)
            prev->left=new node(value);
            else
            prev->right=new node(value);
    }
    void inorder(node *root1)
    {
        if(root1==NULL)
         return;
         inorder(root1->left);
         cout<<root1->key<<" , ";
         inorder(root1->right);
        
    }
  bool search(int value){
       node* p=root;
       while(p){
        if(p->key==value)
          return true;
          else if(value<p->key)
            p=p->left;
           else
             p=p->right;   
       }
       return false;
  }
void breadthfirst(){
      queue<node*> q;
      node* p=root;
      if(root!=NULL)
      {
        q.push(p);
        while(!q.empty()){
            p=q.front();
            q.pop();
            cout<<p->key<<",";
            if(p->left)
             q.push(p->left);
             if(p->right)
             q.push(p->right);
        }
      }
}
node* findmin(node* root1){
  while(root1->right!=NULL){
    root1=root1->right;
  }
  return root1;
}
node* remove(node* temp,int ele){
  
  if(root==NULL)
    return NULL;
    
  else if(ele<temp->key)
     temp->left=remove(temp->left,ele);
  else if(ele>temp->key)   
  temp->right=remove(temp->right,ele);
  else{
    if(temp->left==NULL and temp->right==NULL){
      delete temp;
      temp=NULL;
    }
    else if(temp->left==NULL){
      node* temp1=temp;
      temp=temp1->right;
      delete temp1;
    }
    else if(temp->right==NULL){
       node* temp1=temp;
      temp=temp1->left;
      delete temp1;
    }
    else{
      node* temp1=findmin(temp->left);
      temp->key=temp1->key; 
      temp->left=remove(temp->left,temp1->key);
    }
  }
  return temp;
       
}
int height(node* temp){
  if(root==NULL)
     return 0;
     int h1=height(temp->left);
     int h2=height(temp->right);
     return (1+max(h1,h2));
}
void preorder(node* root1){
  if(!root1)
    return;
    cout<<root1->key<<" ,";
    preorder(root1->left);
    preorder(root1->right);
}
void postorder(node* root1){
  if(!root1)
    return;
    
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->key<<" ,";
}
bool isValidBST(node* root1){
        if(!root1)
            return true;
        if(root1->key > root1->left->key){
            isValidBST(root1->left);
            return true;
        }
        else if(root1->key<root1->right->key){
            isValidBST(root1->right);
            return true;
            
        }
        else 
            return false;
    }
    void replace(BST b,int val,int replv){
      node* p=b.root;
      while(p!=NULL){
        if(p->key>val)
          p=p->left;
         else if(p->key<val)
          p=p->right; 
          else if(p->key==val)
             {
              p->key=replv;
                break;
             }
            
      }
      
      vector<int> v;
      pushinvector(v,b.root); 
      sort(v.begin(), v.end());
      for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ,";
        cout<<endl;

      for(int i=0;i<v.size();i++)
        b.insert(v[i]);

        // inorder(root);
    }
    void pushinvector( vector<int> v,node* root1){
      if(root1==NULL)
         return;
         pushinvector(v,root1->left);
         v.push_back(root1->key);
         pushinvector(v,root1->right);
      

    }
};


int main(){
BST b;
b.insert(2);
    b.insert(10);
    b.insert(9);
    b.insert(4);
    b.insert(3);
    b.insert(4);
    b.insert(7);
    b.insert(4);
b.inorder(b.root);
cout<<endl;
b.replace(b,7,12);
b.inorder(b.root);
// cout<<endl;
// cout<<"The number is :";
// cout<<b.search(7);
// cout<<endl;
// // b.breadthfirst();
// cout<<endl;
// b.remove(b.root,4);
// b.inorder(b.root);

// // cout<<endl<<b.height(b.root);
// cout<<endl;
// b.preorder(b.root);
// cout<<endl;

// b.postorder(b.root);
// cout<<endl;
// b.remove(b.root,10);
// b.inorder(b.root);
// cout<<endl<<"Checking of BSt : "<<b.isValidBST(b.root);
return 0;
}