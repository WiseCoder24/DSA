#include <bits/stdc++.h>
using namespace std;
#include <stack>
class Queue
{
public:
    stack<int> s1;
    stack<int> s2;
    void enque(int x)
    {
        s1.push(x);
    }
    int deque()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool isempty(){
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.enque(1); 
    q.enque(2); 
    q.enque(3); 
    q.enque(4);
    cout<<q.deque()<<endl; 
    q.enque(5);
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
    cout<<q.deque()<<endl;
}