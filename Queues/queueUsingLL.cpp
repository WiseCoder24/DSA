#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:
    node* front;
    node* back;
    Queue(){
        front = NULL;
        back = NULL;
    }
    void enque(int x){
        node* n = new node(x);
        if (front==NULL)
        {
            back=n;
            front=n;
        }
        back->next = n;
        back = n;
    }
    void dequeue(){
        if(front==NULL){
            cout<<"Queue is already empty"<<endl;
            return;
        }
        node* temp;
        temp = front;
        front = front->next;
        delete temp;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is already empty"<<endl;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return false;
        }
        return true;
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
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
}