#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    int val;
    char letter;
    Tree* left;
    Tree* right;
    Tree(int val, char c){
        this->val = val;
        this->letter = c;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<pair<int,char>> freq(string s){
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    vector<pair<int,char>> v;
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]!=0){
        v.push_back(make_pair(mp[s[i]],s[i]));
        mp[s[i]] = 0;

        }
    }

    return v;
}

class Compare
{
public:
    bool operator() (Tree* a, Tree* b)
    {
        if(a->val>b->val)
        return true;
        else
        return false;
    }
};

void print (priority_queue<Tree*, vector<Tree*>,Compare> q){
    while(q.size()){
        cout<<q.top()->letter<<" "<<q.top()->val<<endl;
        q.pop();
    }
}

Tree* makeTree(vector<pair<int,char>> &f){
    priority_queue<Tree*, vector<Tree*>,Compare> q; 
    for (int i = 0; i < f.size(); i++)
    {
        q.push(new Tree(f[i].first,f[i].second));
    }
    // print(q);
    while(q.size()>1){
        Tree* left = q.top();
        q.pop();
        Tree* right = q.top();
        q.pop();

        Tree* nd = new Tree(left->val+right->val,'~');
        nd->left = left;
        nd->right = right;
        q.push(nd);
    }
    return q.top();
}

void getValues(Tree* root,string s, map<char,string> &vtr){
    if(!root)
    return;
    if(root->letter!='~'){
        vtr[root->letter]=s;
        return;
    }
    else{
        getValues(root->left,s+"0",vtr);
        getValues(root->right,s+"1",vtr);
    }
}

string decode(Tree* tree, string s, int &i){
    string str = "";
    while(i<=s.size()){
    if(tree->letter!='~'){
        str+=tree->letter;
        return str;
    }
    else if(s[i]=='0'){
        if(tree->left){
            tree = tree->left;
            i++;
        }
        else
        return str;
    }
    else if(s[i]=='1'){
        if(tree->right){
            tree = tree->right;
            i++;
        }
        else
        return str;
    }
    }
    return "";
}

int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    vector<pair<int,char>> f = freq(s);
    sort(f.begin(),f.end());
    // for(int i=0;i<f.size();i++){
    //     cout<<f[i].first<<" "<<f[i].second<<endl;
    // }
    map<char,string> vtr;
    Tree* tree = makeTree(f);
    getValues(tree,"",vtr);
    string res = "";
    // for(auto i:vtr){
    //     cout<<i.first<<" "<<i.second<<endl;
    //     //res+=i.second;
    // }
    for(auto i:s){
        res+=vtr[i];
    }
    cout<<endl;
    cout<<s<<endl;
    cout<<res<<endl;
    string back="";
    for(int i=0;i<res.size();){
        back+=decode(tree,res,i);
    }
    cout<<back<<endl;

}