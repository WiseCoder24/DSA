#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int total = 0;
void printArr(vector<int> arr){
    for (auto i : arr)
        cout << i << " ";
}

void checksum(vector<int> arr,int k){
    int sum=0;
    for(auto i: arr){
        sum+=i;
    }
    if(sum%k==0){
        total++;
    }
}

void subarray(vector<int> &nums,vector<int> &ans, int k){
    int n = nums.size();
    for(int i=0;i<n;i++){
        // ans.clear();
        for(int j=0;j<n;j++){
            ans.clear();
            for(int k=i;k<=j;k++){
                ans.push_back(nums[k]);
            }
            // printArr(ans);cout<<endl;
            checksum(ans,k);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    int temp;
    int ex;
    for(int i=0;i<n;i++){
        cin>>temp;
        nums.push_back(temp);
    }
    for(auto i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
    cin>>ex;
    subarray(nums,ans,ex);
    cout<<total;
    return 0;
}