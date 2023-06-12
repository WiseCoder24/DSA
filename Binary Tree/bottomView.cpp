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
// void levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     // Initially
//     q.push(root);
//     q.push(NULL);
//     while(!q.empty()){
//         // Step 1
//         Node* temp = q.front();
//         // Step 2
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
            
//             // Step 3
//             cout<<temp->data<<" ";
//             // Step 4
//             if(temp->left) q.push(temp->left);
//             if(temp->right) q.push(temp->right);
//         }
//     }
// }

void printBottomView(Node* root){
    if(root==NULL){
        return;
    }
    // Map for storing top node
    map<int,int> topNode;
    // Storing a pair of node and horizontal distance
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        //create entry
        topNode[hd] = frontNode->data;
        
        
        // Check for subtrees
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    // Now the answer will be stored in the map
    cout<<"Printing answer:"<<endl;
    for(auto i:topNode){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

}

int main()
{
    Node* root = NULL;
    root = buildTree();
    // cout<<"The level order traversel of the tree is: "<<endl;
    // levelOrderTraversal(root);
    printBottomView(root);
}