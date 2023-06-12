#include<bits/stdc++.h>
using namespace std;

int Paths(int start, int end){
    if(start==end){
        return 1;
    }
    if(start>end){
        return 0;
    }
    int c = 0;
    for(int i=1;i<=6;i++){
        c += Paths(start+i,end);
    }
    return c;
}

int main(){
    cout<<Paths(0,3)<<endl;
}