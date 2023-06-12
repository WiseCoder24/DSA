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

void flatten(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        Node* t = root->right;
        while(t->right!=NULL){
            t = t->right;
        }
        t->right = temp;
    }
        flatten(root->right);
}

//Morris traversal
void flatten_Morris(Node* root) {
        
        Node* curr = root;
        while(curr!=NULL){
        
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }   
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
            curr = curr->right;
        }
        /*Root ke left ko null krna (Jugaad)
        curr = root;
        while(curr!=NULL){
            curr->left = NULL;
            curr = curr->right;
        }
        */
    }

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    flatten(root);
    inorderPrint(root);
    cout<<endl;
    return 0;
}