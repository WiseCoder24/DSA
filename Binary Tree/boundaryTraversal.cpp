#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    // 3 steps
    //1
    Node* root = new Node(data);
    cout<<"Enter the data for the left part of "<<data<<endl;
    // 2
    root->left = buildTree();
    cout<<"Enter the data for the right part of "<<data<<endl;
    //3 
    root->right = buildTree();
    
    return root;
}

void printLeftNodes(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left)
        printLeftNodes(root->left);
    else
        printLeftNodes(root->right);
}

void printLeafNodes(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) 
        cout<<root->data<<" ";
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void printRightNodes(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    if(root->right)
        printRightNodes(root->right);
    else
        printRightNodes(root->left);
    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
 
    //Step 1: print all left nodes
    printLeftNodes(root->left);
    // Step 2: print all leaf nodes
    printLeafNodes(root);
    // Step 3: print all right nodes in reverse
    printRightNodes(root->right);

}

int main()
{
    Node* root = NULL;
    root = buildTree();
    // cout<<"The level order traversel of the tree is: "<<endl;
    // levelOrderTraversal(root);
    boundaryTraversal(root);
    // 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1 
}