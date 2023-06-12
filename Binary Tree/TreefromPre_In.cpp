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

int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++)
    {
        if (inorder[i]==curr)
        {
            return i;
        }
        
    }
    
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if (start>end)
    {
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);
    return node;
}

void inorderprint(Node* root){
    if (root == NULL)
    {
        return;
    }
    
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main(){

    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    
    Node* root = buildTree(preorder, inorder, 0, 4);
    inorderprint(root);
}


/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

class Solution {
public:
    int findPosition(vector<int>& inorder, int size, int target){
        // int ans = -1;
        // int s = 0;
        // int e = size-1;
        // int mid = (s+e)/2;
        // while(s<=e){
        //     mid = (s+e)/2;
        //     if(inorder[mid]==target) return mid;
        //     if(target>inorder[mid]) s = mid+1;
        //     if(target<inorder[mid]) e = mid-1;
        // }
        // return ans;
        for(int i=0;i<size;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder,int size,int &preIndex,int inorderStart, int inorderEnd){
        //base case
        if(preIndex>=size || inorderStart>inorderEnd) return NULL;

        //Step 1
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(inorder,size,element);

        //Step 2: Solve root->left
        root->left = solve(inorder,preorder,size,preIndex,inorderStart,pos-1);
        // Step 3: solve root->right
        root->right = solve(inorder,preorder,size,preIndex,pos+1,inorderEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = n-1;
        TreeNode* ans = solve(inorder,preorder,n,preIndex,inorderStart,inorderEnd);
        
        return ans;
    }
};
*/
