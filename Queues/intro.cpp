#include<bits/stdc++.h>
using namespace std;
#define n 20
class Queue{
    int* arr;
    int front;
    int back;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1; 
    }
    void enque(int x){
        if (back==n-1)
        {
            cout<<"Queue overflow";
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
        
    }
 
    void dequeue(){
        if (front == -1 || front>back)
        {
                cout<<"No elements in queue";
        }
        front++;
    }
    int peek(){
        if (front == -1 || front>back)
        {
            cout<<"No elements in queue";
            return -1;
        }   
        return arr[front];
    }
    bool empty(){
        if (front == -1 || front>back)
        {
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
}