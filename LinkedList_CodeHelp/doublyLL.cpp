#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        cout<<"deleting "<<this->data<<endl;
    }
};

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        //If LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //Step 1 Create a node
    Node* newNode = new Node(data);
    // step 2
    newNode->next = head;
    // step 3
    head->prev = newNode;
    // step 4
    head = newNode;
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        //If LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1
    Node* newNode = new Node(data);
    // Step 2
    tail->next = newNode;
    // Step 3
    newNode->prev = tail;
    // Step 4
    tail = newNode;
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(head==NULL){
        //If LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(position == 1){
        insertAtHead(head,tail,data);
    }
    int len = getLength(head);
    if(position>len){
        insertAtTail(head,tail,data);
    }
    // step 1
    Node* prevNode = head;
    
    int i=1;
    while(i<position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;
    // Step 2
    Node* newNode = new Node(data);
    // Step 3
    prevNode->next = newNode;
    // Step 4
    newNode->prev = prevNode;
    // Step 5
    curr->prev = newNode;
    // Step 6
    newNode->next = curr;
}

void deleteAtPosition(Node* &head,Node* &tail,int position){
    if(head==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    if(head->next==NULL){
        // Single node 
        Node* temp = head;
        head = NULL;
        delete temp;
        return;
    }
    if(position==1){
        //Deleting first node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if(position>len){
        cout<<"invalid position"<<endl;
        return;
    }
    if(position == len){
        // Deleting last node
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp; 
    }
    // Deleting node in between
    int i=1;
    Node* left = head;
    while(i<position-1){
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;
    // Step 2
    left->next = right;
    // Step 3
    right->prev = left;
    // Step 4
    curr->next = NULL;
    // Step 5
    curr->prev = NULL;
    // Step 6
    delete curr;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}



int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    // print(first);
    // cout<<endl;
    insertAtHead(head,tail,1);
    insertAtTail(head,tail,40);
    insertAtPosition(head,tail,24,2);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,1);
    // deleteAtPosition(head,tail,5);
    print(head);
    cout<<endl;
    

}