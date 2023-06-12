/*
14. Longest Common Prefix (Leetcode)
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        children[i] = NULL;
                }
                childCount = 0;
                this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->childCount++;
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

}

void findLCP(string first, string &ans, TrieNode* root){
    if(root->isTerminal){
        return;
    }
    for(int i=0;i<first.length();i++){
        char ch = first[i];
        if(root->childCount==1){
            ans.push_back(ch);
            int index = ch-'a';
            root = root->children[index];
        }
        else
            break;
        if(root->isTerminal)
            break;
    }
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //Inserting all strings
        for(int i=0;i<strs.size();i++){
            insertWord(root,strs[i]);
        }
        string ans = "";
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;
    }
};