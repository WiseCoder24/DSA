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

int calHeight(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight,rHeight)+1;
}

// calculate diameter in O(n^2)
int calDiameter(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight+rHeight+1;
    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);
    return max(currDiameter, max(lDiameter,rDiameter));
}

// calculate diameter in O(n)
int calDiameter2(Node* root, int* height){
    if (root==NULL)
    {
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int lDiameter = calDiameter2(root->left, &lh);
    int rDiameter = calDiameter2(root->right, &rh);
    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;
    return max(currDiameter,max(lDiameter,rDiameter));

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // Height
    cout<<calHeight(root)<<endl;
    // Diameter
    cout<<calDiameter(root)<<endl;
    int height = 0;
    cout<<calDiameter2(root, &height)<<endl;
}