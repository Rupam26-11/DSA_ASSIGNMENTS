#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* insert(node* root, int val) {
    if (root == NULL)
        return new node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

node* buildbst(int arr[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    return root;
}


bool isBSTUtil(node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    bool leftCheck = isBSTUtil(root->left, minVal, root->data);
    bool rightCheck = isBSTUtil(root->right, root->data, maxVal);

    if (leftCheck && rightCheck)
        return true;
    else
        return false;
}


bool isBST(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6;

    node* root = buildbst(arr, n);

    if (isBST(root))
        cout << "Valid BST\n";
    else
        cout << "Not a BST\n";

   

    return 0;
}
