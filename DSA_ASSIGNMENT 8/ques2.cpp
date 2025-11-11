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


//SEARCH IN BST 
bool search(node*root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return false;

    }

    else if(root->data>key){
        return search(root->left,key);
    }
        else if(root->data<key){
        return search(root->right,key);
    }
}

//search in bst using iterativ approach
node* searchNode(node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;          

        if (key < root->data)
            root = root->left;     
        else
            root = root->right;    
    }
    return NULL; 
}
//maximum and minimum noddes in a BST
node* findMin(node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

node* findMax(node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}
// INORDER PREDECCESSOR AND SUCCESSOR
node *leftmost(node *root)
{
    node *ans = NULL;
    while (root != NULL)
    {
        ans = root;
        root = root->left;
    }
    return ans;
}

node *rightmost(node *root)
{
    node *ans = NULL;
    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }
    return ans;
}
void getpredsucc(node *root, int key)
{
    node *curr = root;
    node *pred = NULL;
    node *succ = NULL;
    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                // rightmostinleftsubbtree
                pred = rightmost(curr->left);
            }

            if (curr->right != NULL)
            {
                succ = leftmost(curr->right);
            }
            break;
        }
    }
    cout << "predecessor is :" << pred->data;
    cout << "successor is :" << succ->data;
}

int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    node *root = buildbst(arr, 6);
    inorder(root);
    search(root,3);
    //for search iteratuve approach
    int key;
    cout << "Enter value to search: ";
    cin >> key;

    node* result = searchNode(root, key);

    if (result != NULL)
        cout << "Node " << key << " found in BST.\n";
    else
        cout << "Node " << key << " not found in BST.\n";
  


    //max and min
    
    node* minn = findMin(root);
    node* maxx = findMax(root);

    cout << "Minimum element in BST = " << minn->data << endl;
    cout << "Maximum element in BST = " << maxx->data << endl;
//inorder predeecesor and sucesssor

    getpredsucc(root, 8);
    return 0;
}