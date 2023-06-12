#include<iostream>
#include<stack>
using namespace std;

void insertatBottom(stack<int> &st,int ele){
    
    if (st.empty())
    {
        st.push(ele);
        return; 
    }
    
    int topele = st.top();
    st.pop();
    insertatBottom(st,ele);
    st.push(topele);

}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int target = st.top();
    st.pop();

    //recursion
    reverseStack(st);
    //inserting at bottom
    insertatBottom(st,target);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}