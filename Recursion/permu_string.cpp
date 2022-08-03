#include<bits/stdc++.h>
using namespace std;

void permutations(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string restOfString = s.substr(0,i)+s.substr(i+1);

        permutations(restOfString,ans+ch);
    }
    
}

int main(){
    
    permutations("ABC","");

}