#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int size,int key){
    if(size==0) return false;
    if(arr[0]==key) return true;
    else{
        bool remaining = linearSearch(arr+1,size-1,key);
        return remaining;
    }
}

bool binarySearch(int arr[],int start,int end,int key){
    //base case
    if(start>end) return false;
    int mid = (start+end)/2;
    if(arr[mid]==key) return true;
    if(arr[mid]<key){
        //check right half
        return binarySearch(arr,mid+1,end,key);
    } 
    else{
        //check left half
        return binarySearch(arr,start,mid-1,key);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bool ans = linearSearch(arr,n,6);
    if(ans){
        cout<<"The key is found"<<endl;
    }
    else{
        cout<<"The key not found"<<endl;
    }

    bool ans2 = binarySearch(arr,0,n-1,1);
    if(ans2){
        cout<<"The key is found (Binary search)"<<endl;
    }
    else{
        cout<<"The key not found (Binary search)"<<endl;
    }
}