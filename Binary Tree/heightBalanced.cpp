#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calHeight(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight,rHeight)+1;
}

bool isBalanced(Node* root){
    if (root==NULL)
    {
        return true;
    }
    if (isBalanced(root->left)==false)
    {
        return false;
    }
    if (isBalanced(root->right)==false)
    {
        return false;
    }
    int lh = calHeight(root->left);
    int rh = calHeight(root->right);
    if (abs(lh - rh)<=1)
    {
        return true;
    }
    else{
        return false;   
    }
    
}

int main(){
    // tree 1
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // for tree 1
    cout<<isBalanced(root)<<endl;

    // tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    // for tree 2
    cout<<isBalanced(root2)<<endl;
}