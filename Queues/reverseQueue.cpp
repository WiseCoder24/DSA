#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printQueue(q);
    cout<<endl;
    reverseQueue(q);
    printQueue(q);
}