#include<bits/stdc++.h>
using namespace std;

void fullPyramid(){
    int n;
    cin>>n;
    for (int row = 0; row < n; row++)
    {
        //spaces
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        
        //numbers
        for (int col = 0; col < row+1; col++)
        {
            cout<<row+col+1;
        }
        //reverse numbers
        int start = 2*row;
        for (int col = 0; col < row; col++)
        {
            cout<<start--;
        }
        cout<<endl;
        
    }
    
    // for (int row = 0; row < n; row++)
    // {
    //     int start = row+1;
    //     for (int col = 0; col < row+1; col++)
    //     {
    //         cout<<start++<<" ";
    //         or cout<<row+col+1<<" "; 
    //     }
    //     cout<<endl;
    // }
    
}

int main(){
    fullPyramid();
    return 0;
}