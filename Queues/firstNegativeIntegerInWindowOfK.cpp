// FIRST NEGATIVE INTEGER IN EVERY WINDOW OF K
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr,int n,int k){
    deque<int> q;
    // process first window of size k
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    // Processing remaining windows
    for(int i=k;i<n;i++){
        // Purani window ka answer dedo
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
        // Out of window element ko remove kar do
        while((!q.empty()) && (i-q.front()>=k)){
            q.pop_front();

            // Check curr element for insertion
        
        }
        if(arr[i]<0) q.push_back(i);
    }
    //last window ka answer print krdo
    if(q.empty()){
        cout<<0<<" ";
    }
    else{
        cout<<arr[q.front()]<<" ";
    }
}

int main(){
    vector<int> arr = {12,-1,-7,8,-15,20,16,20};
    int n = 8;
    int k =3;
    solve(arr,n,k);
    
}