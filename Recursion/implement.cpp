#include<bits/stdc++.h>
using namespace std;
int c = 0;
void rec(){
    if(c>10)
    return;
    cout<<c<<endl;
    c++;
    rec();
}

int main(){
    rec();
}