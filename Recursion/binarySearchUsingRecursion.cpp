#include<bits/stdc++.h>
using namespace std;

bool bs(vector<int> &arr, int start, int end, int target){
    if(start>end){
        return false;
    }
    int mid = start+(end-start)/2;
    if(arr[mid]==target) return true;
    if(arr[mid]<target){
    int rightSearch = bs(arr,mid+1,end,target); 
    }
    else{
    int leftSearch = bs(arr,start,mid-1,target); 
    }
    
}
int main(){
    vector<int> arr = {10,20,30,40,50};
    int start = 0;
    int end = arr.size()-1;
    int target = 60;
    if(bs(arr,start,end,target)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
        
    }
}