#include<bits/stdc++.h>
using namespace std;

// void permutations(string s, string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     for (int i = 0; i < s.length(); i++)
//     {
//         char ch = s[i];
//         string restOfString = s.substr(0,i)+s.substr(i+1);

//         permutations(restOfString,ans+ch);
//     }
    
// }

void printPermutations(string &str,int i){
    if(i>=str.size()){
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<str.size();j++){
        //swap
        swap(str[i],str[j]);
        //Recursive call
        printPermutations(str,i+1);
        //backtracking
        swap(str[i],str[j]);

    }
}

int main(){
    
    // permutations("ABC","");
    string s = "abc";
    int i = 0;
    printPermutations(s,i);

}