#include <iostream>
using namespace std;
#define n 50
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr = new int[n];
        top = -1;
    }
    
    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]= x;
    }
    
    void pop(){
        if(top==-1){
            cout<<"Stack is already empty"<<endl;
            return;
        }
        top--;
    }

    int top_element(){
        if(top==-1){
            cout<<"There is no element"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(5);
    cout<<st.top_element()<<endl;
    st.pop();
    cout<<st.top_element()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}