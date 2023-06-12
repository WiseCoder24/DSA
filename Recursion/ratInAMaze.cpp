#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j, int row, int col, vector<vector<int>> &maze,vector<vector<bool>> &visited){
    if( (i>=0 && i<row) && (j>=0 && j<col) && (maze[i][j]==1) && visited[i][j]==false){
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(vector<vector<int>> &maze,int row,int col, int i,int j,vector<vector<bool>> &visited,vector<string> &path, string output){
    if(i==row-1 && j==col-1){
        //Answer found
        path.push_back(output);
        return;
    } 
    //Down (i+1,j)
    if(isSafe(i+1,j,row,col,maze,visited)){
        visited[i+1][j] = true;
        solveMaze(maze,row,col,i+1,j,visited,path,output+"D");
        //backtrack
        visited[i+1][j] = false;
    }

    //left (i,j-1)
    if(isSafe(i,j-1,row,col,maze,visited)){
        visited[i][j-1] = true;
        solveMaze(maze,row,col,i,j-1,visited,path,output+"L");
        //backtrack
        visited[i][j-1] = false;
    }
    //Right (i,j+1)
    if(isSafe(i,j+1,row,col,maze,visited)){
        visited[i][j+1] = true;
        solveMaze(maze,row,col,i,j+1,visited,path,output+"R");
        //backtrack
        visited[i][j+1] = false;
    }
    //Up (i-1,j)
    if(isSafe(i-1,j,row,col,maze,visited)){
        visited[i-1][j] = true;
        solveMaze(maze,row,col,i-1,j,visited,path,output+"U");
        //backtrack
        visited[i-1][j] = false;
    }
}

int main(){
    vector<vector<int>> maze = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };
    //edge case
    if(maze[0][0]==0){
        cout<<"No path exists"<<endl;
        return 0;
    }
    int row = 3;
    int col = 3;
    vector<vector<bool>> visited(row,vector<bool>(row,false));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    solveMaze(maze, row,col, 0,0,visited, path, output);
    //If there is no solution
    if(path.size()==0){
        cout<<"No path exists"<<endl;
        return 0;
    }
    for(auto i:path){
        cout<<i<<" ";
    }cout<<endl;
}