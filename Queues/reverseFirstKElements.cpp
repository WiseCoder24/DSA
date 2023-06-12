#include <bits/stdc++.h>
using namespace std;
// REVERSE FIRST K ELEMENTS OF A QUEUE
void reverseK(queue<int> &q, int k){
    stack<int> s;
    int n = q.size();
    int count = 0;
    if(k<=0||k>n) return;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;
        if(count==k) break;
    }
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
    count = 0;
    while(!q.empty() && (n-k)!=0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count==n-k) break;
    }
}

void printQueue(queue<int> q){
    if(q.empty()){
        return;
    }
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    printQueue(q);
    cout<<endl;
    reverseK(q,5);
    printQueue(q);
}