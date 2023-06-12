#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int s, int e){
    int mid = s+(e-s)/2;
    int l1 = mid-s+1; 
    vector<int>v1(l1);
    int l2 = e-mid;
    vector<int>v2(l2);
    
    int k=s;
    for(int i=0;i<l1;i++){
        v1[i] = arr[k];
        k++;
    }
    for(int i=0;i<l2;i++){
        v2[i]=arr[k];
        k++;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while(leftIndex<l1 && rightIndex<l2){
        if(v1[leftIndex]<v2[rightIndex]){
            arr[mainIndex] = v1[leftIndex];
            leftIndex++;
            mainIndex++;
        }
        else{
            arr[mainIndex] = v2[rightIndex];
            rightIndex++;
            mainIndex++;
        }
    }
    while(leftIndex<l1){
        arr[mainIndex++] = v1[leftIndex++];
    }
    while(rightIndex<l2){
        arr[mainIndex++] = v2[rightIndex++];
    }

}

void mergeSort(vector<int> &arr,int s, int e){
    //base case
    if(s>=e) return;
    int mid = s+(e-s)/2;
    //left part
    mergeSort(arr,s,mid);
    //right part
    mergeSort(arr,mid+1,e);
    //now merge two sorted arrays
    merge(arr,s,e);

}

int main() {
    vector<int> arr = {4,5,13,2,12};
    int s = 0;
    int e = arr.size()-1;
    mergeSort(arr,s,e);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}