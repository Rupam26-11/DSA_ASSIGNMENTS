#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
node *insert(node *root, int val)
{
    if (root == NULL)//khali jab hei
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

node *buildbst(int arr[], int size)
{
    node *root = NULL;//starting mei khali hei isilye  
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
void inorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

//delete in bst
node* getinordersuccessor(node*root){
          while( root->left=NULL){
            root=root->left;
          }
          return root;
}
node* deletenode(node*root,int key){
    if(root==NULL){
        return NULL;}
       if(root->data>key){
        root->left= deletenode(root->left,key);
    }
        else if(root->data<key){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }   
        else if(root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }  
        else{
            node*is=getinordersuccessor(root->right);
            root->data=is->data;
            root->right=deletenode(root->right,is->data);
        }
    }
return root;
}
//maxdepth and min depth
int maxDepth(node* root) {
    if (root == NULL)
        return 0;  // depth = 0 for empty tree
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}


int minDepth(node* root) {
    if (root == NULL)
        return 0;

    // Calculate depths of left and right
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    // If one side is missing, we must take the other side
    if (root->left == NULL)
        return 1 + rightDepth;
    if (root->right == NULL)
        return 1 + leftDepth;

    // Both children exist → take the smaller one
    return 1 + min(leftDepth, rightDepth);
}


int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    node *root = buildbst(arr, 6);
    inorder(root);
   deletenode(root,5);
   
    cout << "Maximum Depth of the tree = " << maxDepth(root) << endl;
    cout << "Minimum Depth of the tree = " << minDepth(root) << endl;
    return 0;
}
