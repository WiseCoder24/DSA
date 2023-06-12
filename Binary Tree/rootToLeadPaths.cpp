#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
    // TreeNode(int x, TreeNode *left,TreeNode *right){
    //     val = x;
    //     left = left;
    //     right = right;
    // }
};

void printArr(vector<int> path, int pathlength){
    int i;
    for( i=0;i<pathlength;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void getPaths(TreeNode* root, vector<int> path, int pathlength){
    if(root==NULL)
    return;
    path.push_back(root->val);
    pathlength++;
    if(root->left==NULL && root->right==NULL){
        cout<<"Leaf found"<<endl;
    printArr(path,pathlength);
    }

    else{
getPaths(root->left,path,pathlength);
    getPaths(root->right,path,pathlength);
    }
    
}

void printPreorder(TreeNode* root){
        if(root==NULL)
        return;
        cout<<root->val<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

int main(){
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(9);
        root->right = new TreeNode(0);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(1);
        printPreorder(root);
        vector<int> path;
        int pathlength = 0;
        getPaths(root, path, pathlength);
        }