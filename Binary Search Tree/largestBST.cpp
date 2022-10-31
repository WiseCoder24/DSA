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

struct info{
    int subtreeSize;
    int max;
    int min;
    int sizeOfLarBST;
    bool isBST;
};

info LargestBST(Node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    info leftInfo = LargestBST(root->left);
    info rightInfo = LargestBST(root->right);

    info curr;
    curr.subtreeSize = (1+leftInfo.subtreeSize +rightInfo.subtreeSize);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max = max(rightInfo.max,max(leftInfo.max,root->data));
        curr.sizeOfLarBST = curr.subtreeSize;
        curr.isBST = true;
        return curr;
    }
    curr.sizeOfLarBST = max(leftInfo.sizeOfLarBST, rightInfo.sizeOfLarBST);
    curr.isBST = false;
    return curr;
}

int main(){
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout<<"Size of largest BST is: "<<LargestBST(root).sizeOfLarBST<<endl;
}