#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* inorderSucc(Node* root){
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){

    if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else{
        // key == root->data
        if (root->left == NULL)
        {
            Node* temp = root-> right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //Case 3
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
        
    }
    return root;
}

void printinorder(Node* root){
    if (root == NULL)
    {
        return; 
    }
    
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    printinorder(root);
    cout<<endl;
    root = deleteInBST(root, 2);
    // Inorder traversal gives the sorted array for Binary Search Tree.
    printinorder(root);
    return 0;
}