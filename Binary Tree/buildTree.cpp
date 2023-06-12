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

// Level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    // Initially
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        // Step 1
        Node* temp = q.front();
        // Step 2
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            
            // Step 3
            cout<<temp->data<<" ";
            // Step 4
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    cout<<"The level order traversel of the tree is: "<<endl;
    levelOrderTraversal(root);
}