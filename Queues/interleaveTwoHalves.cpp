#include <bits/stdc++.h>
using namespace std;
void interleaveQueue(queue<int> &q){
    int n = q.size();
    int k = n/2;
    int count=0;
    queue<int>q2;
    // Step 1
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;
        if(count==k) break;
    }
    //Step 2
    while(!q.empty()&& !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);
    }
    if(n&1){
        //If n is odd
        int temp = q.front();
        q.pop();
        q.push(temp);
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
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    interleaveQueue(q);
    printQueue(q);
}