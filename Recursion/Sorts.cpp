#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e){
    int mid = (s+e)/2;
    int l1 = mid-s+1;
    int l2 = e-mid;
    vector<int> v1;
    v1.resize(l1);
    vector<int> v2;
    v2.resize(l2);

    //Copying values
    int mainArrayIndex = s;
    for(int i=0;i<l1;i++){
        v1[i] = arr[mainArrayIndex++];
    } 
    mainArrayIndex = mid+1;
    for (int i = 0; i < l2; i++)
    {
        v2[i] = arr[mainArrayIndex++];
    }

    // Merge two sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while(index1<l1 && index2<l2){
        if(v1[index1]<v2[index2]){
            arr[mainArrayIndex++] = v1[index1++];
        }
        else {
            arr[mainArrayIndex++] = v2[index2++];
        }

    }
    while(index1<l1){
        arr[mainArrayIndex++] = v1[index1++];
    }
    while (index2<l2)
    {
        arr[mainArrayIndex++] = v2[index2++];
    }
    
    
}

void mergeSort(vector<int> &arr,int s, int e){
    //base case
    if(s>=e) return;
    int mid = s + (e-s)/2;
    //sorting left part
    mergeSort(arr,s,mid);

    // sorting right part
    mergeSort(arr,mid+1,e);

    merge(arr, s, e);
}

int main(){
    vector<int> arr = {2, 6, 1, 29, 63};
    int n = arr.size();
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
    mergeSort(arr,0,n-1);
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}