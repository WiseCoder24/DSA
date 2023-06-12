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

// void leftView(Node* root){
//     if(root==NULL){
//         return;
//     }
//     queue<Node*>q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int n = q.size();
//         for (int i = 0; i < n; i++)
//         {
//             Node* curr = q.front();
//             q.pop();
//             if(i == 0){
//                 cout<<curr->data<<" ";
//             }
//             if(curr->left!=NULL){
//                 q.push(curr->left);
//             }
//             if (curr->right!=NULL)
//             {
//                 q.push(curr->right);
//             }            
//         }       
//     }    
// }

void printLeftView(Node* root, vector<int> &ans, int level){
    //Base case 
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    //left
    printLeftView(root->left,ans,level+1);
    //Right
    printLeftView(root->right,ans,level+1);
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // leftView(root);
    vector<int> ans;
    int level=0;
    printLeftView(root,ans,level);
    for(auto i:ans){
        cout<<i<<" ";
    }
}