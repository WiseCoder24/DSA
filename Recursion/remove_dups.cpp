#include<bits/stdc++.h>
using namespace std;

string removeDups(string s){
    if(s.length()==0){
        return "";
    }
    char c = s[0];
    string ans = removeDups(s.substr(1));
    if(c==ans[0]){
        return ans;
    }
    else{
        return c+ans;
    }
}

int main(){
   cout<<removeDups("aaaabbbeeecdddd");
}