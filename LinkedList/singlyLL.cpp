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

void deleteAtHead(node* &head){
    node* delHead = head;
    head = head->next;
    delete delHead;
}

void deleteNode(node* &head, int val){
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while (temp->next->data!= val)
    {
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    
}

// Iterative method to reverse a linked list
node* itReverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    while (curr!=NULL)
    {
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }
    return prev;
}

// recurrsive method to reverse a linked list 
node* recurrReverse(node* &head){

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    

    node* newhead = recurrReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

// Reversing K nodes of a linked list 
node* reverseK(node* &head, int val){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;
    int count = 0;
    while (curr!=NULL && count< val)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    if (nextptr!=NULL)
    {
        head->next = reverseK(nextptr, val);
    }
    
    return prev;
}

// Function to create a cycle in a linked list 
void makeCycle(node* head, int pos){
    node* temp = head;
    node* startNode;
    int count = 1;
    while (temp->next!=NULL)
    {
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;

}

// Function to detect the presence of cycle in a linked list 
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
        
    }
    return false;
}

// Function to remove cycle in a linked list 
void removeCycle(node* head){
    node* slow = head;
    node* fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);
    fast = head;
    while (fast->next!=slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = NULL;
    
}

// function to know the length of the linked list 
int length(node* &head){
    int l = 0;
    node* temp = head; 
    while (temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

// Function to append k last nodes in a linked list 
node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = length(head);
    int count = 1;
    // if k is greater than l 
    k = k%l;
    while (tail->next!=NULL)
    {
        if (count ==l-k)
        {
            newTail = tail;
        }
        if (count == l-k+1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
        
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;

}

// Function to create the intersection 
void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while (temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    
}

//Function to check Intersection of two linked lists 
int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if (l1>l2)
    {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr2 = head1;
        ptr1 = head2;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        d--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;
}

// Function to merge two sorted linked lists in iterative way
node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;
    while (p1!=NULL && p2!= NULL)
    {
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1!=NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2!=NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    
    return dummyNode->next;
}

// Function to merge two sorted linked lists in recurrsive way
node* mergeRecurrsive(node* &head1, node* &head2){
    node* result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecurrsive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecurrsive(head1, head2->next);
    }

    return result;
}

// Problem: Put even position nodes after odd position nodes 
void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }

}

int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    // insertAtHead(head,7);
    display(head);
    // if(search(head,6)){
    //     cout<<"The element is present in the linked list"<<endl;
    // }
    // else{
    //     cout<<"The element is not present in the linked list"<<endl;
    // }
    deleteNode(head,1);
    // deleteAtHead(head);

    // node* newhead = itReverse(head);
    // node* newhead2 = recurrReverse(head);
    // node* newhead3 = reverseK(head,2);
    // display(newhead);
    // display(newhead2);
    // display(newhead3);

    // makeCycle(head, 3);
    // cout<<detectCycle(head)<<endl;

    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;

    // node* khead = kappend(head,3);
    // display(khead);
    // node* head1 = NULL;
    // node* head2 = NULL;
    // insertAtTail(head1,1);
    // insertAtTail(head1,2);
    // insertAtTail(head1,3);
    // insertAtTail(head1,4);
    // insertAtTail(head1,5);
    // insertAtTail(head1,6);
    // insertAtTail(head2,9);
    // insertAtTail(head2,10);
    // intersect(head1, head2, 3);
    // display(head1);
    // display(head2);
    // cout<<intersection(head1,head2)<<endl;
    // node* head3 = merge(head1, head2);
    // node* head4 = mergeRecurrsive(head1, head2);
    // display(head3);
    // display(head4);
    evenAfterOdd(head);
    display(head);

    return 0;
}