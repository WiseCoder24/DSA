#include<bits/stdc++.h>
using namespace std;

// node structure 
class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    

    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    
}

void insertAtPos(node* head, int val, int pos){
    node* temp = head;
    node* temp2;
node* newnode=new node(val);
    while ((pos-1)!=0)
    {
        temp = temp->next; 
        pos--;
    }
    temp2 = temp->next;
    temp->next=newnode;
    newnode->next = temp2;
    
    // head = temp;
    
}

void display(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

bool search(node*head, int key){
    node* temp = head;
    while (temp!=NULL)
    {
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtPos(head,8,2);
    display(head);
}