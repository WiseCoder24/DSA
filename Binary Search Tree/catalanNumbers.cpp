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
int catalan(int n){
    int result=0;
    if (n<=1)
    {
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        result += catalan(i) * catalan(n-i-1);
    }
    return result;
}

// Possible number of BSTs using catalan numbers
vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if (start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    
    for (int i = start; i <=end; i++)
    {
        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, end);
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node* left = leftSubtrees[j];
            for(int k=0; k< rightSubtrees.size(); k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
        
    }
    return trees;
}

void preorder(Node* root){
    if (root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n = 10;
    cout<<"catalan numbers for n are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<catalan(i)<<" ";
    }
    cout<<endl;
    // Construct trees
    vector<Node*> totalTrees = constructTrees(1,3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    
}