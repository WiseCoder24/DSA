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

int sumAtk(Node* root, int k){
    int sum = 0;
    int level = 0;
    if (root == NULL)
    {
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if (node != NULL)
        {
            if(level == k)
                sum += node->data;
            if (node->left!=NULL)
            {
                q.push(node->left);
            }
            if (node->right!=NULL)
            {
                q.push(node->right);
            }
            }
            else if(!q.empty()){
                q.push(NULL);
                level++;
            }         
    }
    return sum;
}

void printLevelOrder(Node* root){
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout<<node->data<<" ";
            if (node->left!=NULL)
            {
                q.push(node->left);
            }
            if (node->right!=NULL)
            {
                q.push(node->right);
            }
            }
            else if(!q.empty()){
                q.push(NULL);
            }
                   
    }

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //Level order Traversal
    printLevelOrder(root);
    cout<<endl;
    // Practice sum at Kth level during revision
    cout<<sumAtk(root, 2);
}