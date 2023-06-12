// Insert An Element At Its Bottom In A Given Stack
#include <bits/stdc++.h> 
using namespace std;
void pushBottom(stack<int>& myStack, int x){
    //Base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int temp = myStack.top();
    myStack.pop();
    //recursion
    pushBottom(myStack,x);
    // backtrack
    myStack.push(temp);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    pushBottom(myStack,x);
    return myStack;
}
