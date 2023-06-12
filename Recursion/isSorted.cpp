#include<bits/stdc++.h>
using namespace std;

int recurSum(int arr[],int size){
    if(size==1) return arr[0];
    int sum = arr[0]+recurSum(arr+1,size-1);
    return sum;
}

bool isSorted(int arr[],int size){
    if(size==0 || size==1) return true;
    if(arr[0]>arr[1]) return false;
    else{
        bool remainingArr = isSorted(arr+1,size-1);
        return remainingArr;
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
    bool ans = isSorted(arr,n);
    int sum = recurSum(arr,n);
    cout<<"The sum of elements in the array is "<<sum<<endl;
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    
}