#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();
    //outer loop -> (n-1) rounds
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        // To find index of min element from i+1 to n
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        //Swap
        swap(arr[i],arr[minIndex]);
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}