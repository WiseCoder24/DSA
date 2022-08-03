#include<bits/stdc++.h>
using namespace std;

void allSubstrings(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c = s[0];
    string ros = s.substr(1);
    allSubstrings(ros,ans);
    allSubstrings(ros,ans+c);
}

int main(){
    
    allSubstrings("ABC","");

}