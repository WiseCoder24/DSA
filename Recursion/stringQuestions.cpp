#include<bits/stdc++.h>
using namespace std;
// Reverse string using recursion
void reverse(string &s,int start,int end){
    if(start>end){
        return;
    }
    swap(s[start++],s[end--]);
    reverse(s,start,end);
}

//Check palindrome using recursion 
bool checkPalidrome(string num,int i,int j){
    if(i>j){
        return true;
    }
    if(num[i++]==num[j--])return true;
    return false;
    checkPalidrome(num,i,j);
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    cout<<n<<endl;
    cout<<"The string "<<s<<endl;
    // cout<<s[2]<<endl;
    reverse(s,0,n-1);
    cout<<"The string "<<s<<endl;
    if(checkPalidrome(s,0,n-1)){
        cout<<"The string is palindrome"<<endl;
    }
    else{
        cout<<"The string is not palindrome"<<endl;
    }
}