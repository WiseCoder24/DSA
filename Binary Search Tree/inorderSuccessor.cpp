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

Node* insertBST(Node* root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else{
        // val > root->data
        root->right = insertBST(root->right, val);
    }
    return root;  
}

/*Time complexity = O(height of tree)
  space complexity = O(1)
*/

int inorderSuccessor(Node* root, int value){
    int successor = INT_MIN;
    while(root!=NULL){
        if(root->data<=value){
            root = root->right;
        }
        else{
            successor = root->data;
            root = root->left;
        }
    }
    return successor;
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
    Node* root = NULL;
    root = insertBST(root,5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    // Inorder traversal gives the sorted array for Binary Search Tree.
    printinorder(root);
    cout<<endl;
    //Inorder successor
    cout<<"The inorder successor of 3 is "<<inorderSuccessor(root,3)<<endl;
    return 0;
}