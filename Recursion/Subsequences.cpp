/*
Time complexity = 2^n x n
Space complexity = O(n)
*/
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr){
    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
}

void generateSubsequence(int idx, vector<int> ans, vector<int> arr){
    if(idx >= arr.size()){
        printArr(ans);
        return;
    }
    ans.push_back(arr[idx]);
    generateSubsequence(idx+1,ans,arr);
    ans.pop_back();
    generateSubsequence(idx+1,ans,arr);
}

int main(){
    vector<int> arr;
    int idx = 0;
    int n;
    cin>>n;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        arr.push_back(ele);
    }
    for (auto i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> ans;
    generateSubsequence(idx,ans,arr);
    
    return 0;
}