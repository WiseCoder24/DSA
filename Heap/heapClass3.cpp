#include<bits/stdc++.h>
using namespace std;

class Info{
    public:
    int data;
    int row;
    int col;
    Info(int val,int r, int c){
        data = val;
        row = r;
        col = c;

    }
};

class compare{
    public:
    bool operator()(Info* a,Info* b){
        return a->data>b->data;
    }
};

vector<int> mergeKSortedArrays(int arr[][4],int k, int n){
    // Creating minHeap
    priority_queue<Info*,vector<Info*>,compare> minHeap;
    // insert first element of each array
    for(int i=0;i<k;i++){
        Info* temp = new Info(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while(!minHeap.empty()){
        Info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();
        ans.push_back(topElement);
        if(topCol+1<n){
            Info* newInfo = new Info(arr[topRow][topCol+1],topRow,topCol+1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}

int main(){
    int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int k=3;
    int n=4;
    vector<int> ans = mergeKSortedArrays(arr,k,n);
    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;
}


///////////////////////////////////////////////////////////////
/**************************Merge K sorted Linked list***********************************/
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k=lists.size();
        if(k==0) return NULL;

        // Add first element of every list in minHeap
        for(int i=0;i<k;i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();
            // temp may or may not be the first element of the answer linked list
            if(head==NULL){
                // temp is the first element of ans LL
                head=temp;
                tail=temp;
                
            }
            else{
                // temp is not the first element
                tail->next = temp;
                tail = temp;
               
            }
            // This step is common for both above cases. It means if the next element of the list is not null then it is pushed in the min heap
            if(tail->next!=NULL){
                    minHeap.push(tail->next);
                }
        }
        return head;
    }
};