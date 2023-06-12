#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board,int n){
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<int>> &board,int n){
    //Checking whether it is safe to keep queen in current cell
    int i=row;
    int j = col;
    //check row
    while(j>=0){
        if(board[i][j]==1) return false;
        j--;
    }
    //check upper left diagonal
    i=row;
    j = col;
    while(i>=0 && j>=0){
        if(board[i][j]==1) return false;
        i--;
        j--;
    }
    //check bottom left diagonal
    i=row;
    j = col;
    while(i<n && j>=0){
        if(board[i][j]==1) return false;
        i++;
        j--;
    }

    //No queen found, means the position is safe
    return true;

}

void solve(vector<vector<int>> &board, int col, int n){
    //base case
    if(col>=n) {
        printSolution(board,n); 
        return;
    }
    //recursion
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;
            solve(board, col+1,n);

        //backtracking
        board[row][col] = 0;
        }
        
        
    }

}

int main(){
    int n=4;
    vector<vector<int>> board(n,vector<int>(n,0));
    int col = 0;
    solve(board, col, n);
}