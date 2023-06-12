#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int s, int e){
    //Choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    //Find right place for pivot element and place it there
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement) count++;
    }
    // Getting the right position of the pivot
    int rightIndex = s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex;

    //Left mein chhote right mein bade elements
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }


    }
    return pivotIndex;
}
void quickSort(vector<int> &arr, int s, int e){
    //Base case
    if(s>=e) return;
    //partition
    int p = partition(arr,s,e);
    //recursive calls
    // left
    quickSort(arr,s,p-1);
    //right
    quickSort(arr,p+1,e);
}
int main(){
    vector<int> arr = {8,1,3,3,4,20,4,4,50,30};
    int n = arr.size();
    int s = 0; int e =  n-1;
    quickSort(arr,s,e);
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;
}