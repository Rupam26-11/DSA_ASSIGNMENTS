#include <iostream>
using namespace std;
 class node{
    public:
    int data;
    node*left;
    node*right;

    node(int val){
        data=val;
        left=right=NULL;
    }
 };
  
 static int  idx=-1;
 node* buildtree(int arr[],int size){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    node*root= new node(arr[idx]);
    root->left=buildtree(arr,20);
    root->right=buildtree(arr,20);
     
    return root;
 
 }
 //traversal preorder
void preorder(node*root){

    if(root==NULL){
        return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
//traversal inorder
void inorder(node*root){

    if(root==NULL){
        return ;
    }
   
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
//traversal post order
void postorder(node*root){

    if(root==NULL){
        return ;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
int main() {
    int arr[20]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node*root=buildtree(arr,20);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    
    return 0;
} 