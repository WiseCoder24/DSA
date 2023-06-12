#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Inserting node at the head of the linked list
void insertAtHead(Node* &head,Node* &tail, int val){
    //Checking for empty list
    if(head==NULL){
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    //Step 1
    Node* temp = new Node(val);
    //Step 2
    temp->next = head;
    //Step 3   
    head = temp;
}

//Inserting node at the end of the linked list
void insertAtTail(Node* &head, Node* &tail, int val){
    if(head==NULL){
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1
    Node* newNode = new Node(val);
    // step 2
    tail->next = newNode;
    // step 3
    tail = newNode;

}

int findLength(Node* &head){
    if(head==NULL) return 0;
    int length = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

//Inserting at any place (With respect to a position or a value)
void insertAtPosition(int val,int position, Node* &head, Node* &tail){
    if(head==NULL){
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1 Find the position: prev and curr
    if(position==0){
        insertAtHead(head, tail,val);
        return;
    }
    int len = findLength(head);
    if(position >= len){
        insertAtTail(head,tail,val);
        return;
    }
    int i=1;
    Node* prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step 2 
    Node* newNode = new Node(val);

    // Step 3
    newNode->next = curr;

    //Step 4
    prev->next = newNode;

}

void deleteNode(int position, Node* &head, Node* &tail){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    // Deleting first Node
    if(position==1){
        Node* temp= head;
        head = head->next;
        temp->next = NULL;
        delete temp; //Destructor calling
        return;
    }
    //Deleting last node
    int len = findLength(head);
    if(position==len){
        //Find prev
        int i=1;
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;
        }
        //Step 2
        prev->next = NULL;
        //Step 3
        Node* temp = tail;
        //Step 4
        tail = prev;
        //Step 5
        delete temp;
        return;
    }
    // Deleting node in between
    // Step 1
    int i=1;
    Node* prev = head;
    while(i<position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    // cout<<curr->data<<" "<<prev->data<<endl;
    // Step 2
    prev->next = curr->next;
    //Step 3
    curr->next = NULL;
    // Step 4
    delete curr;
    
}

void print(Node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while (temp!=NULL) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,8);
    insertAtHead(head,tail,7);
    insertAtTail(head, tail,11);
    cout<<"Printing list"<<endl;
    print(head);
    cout<<endl;
    insertAtPosition(101,3,head,tail);  
    insertAtPosition(102,0,head,tail);  
    insertAtPosition(103,6,head,tail); 
    print(head);    
    // deleteNode(7,head,tail);
    // deleteNode(1,head,tail);
    // cout<<endl;
    // print(head);
    deleteNode(3,head,tail);
    cout<<endl;
    print(head);
}