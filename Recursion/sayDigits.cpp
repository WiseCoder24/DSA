#include<bits/stdc++.h>
using namespace std;

void sayDigit(int n,vector<string> &ans,string arr[]){
    //Base case
    if(n==0){
        return;
    }
    //Processing
    int digit = n%10;
    n = n/10;
    sayDigit(n,ans,arr);
    ans.push_back(arr[digit]); 
}

int main(){
    int n;
    cin>>n;
    vector<string> ans;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    sayDigit(n,ans,arr);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}