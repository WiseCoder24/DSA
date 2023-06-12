#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st,int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    if(st.top()>=target){
        st.push(target);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertSorted(st,target);
    st.push(topElement);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st,topElement);
}

int main(){
    stack<int> st;
    st.push(3);
    st.push(6);
    st.push(8);
    st.push(1);
    st.push(9);
    st.push(5);
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}