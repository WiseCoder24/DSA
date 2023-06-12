#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size = 0;
    Heap(){
        arr[0] = -1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"No element to be deleted"<<endl;
            return;
        }
        //Replace root with last node 
        arr[1] = arr[size];
        //Remove last node
        size--;
        // Giving node it's correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[leftIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void printMaxHeap(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main(){

    Heap h;
    h.insert(70);
    h.insert(50);
    // h.printMaxHeap();
    h.insert(40);
    h.insert(60);
    h.insert(30);
    h.printMaxHeap();
    h.deleteFromHeap();
    h.printMaxHeap();
    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

cout<<"The heapified array is: ";
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;

heapSort(arr, n);
cout<<"Heap sort: ";
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;


    return 0;
}