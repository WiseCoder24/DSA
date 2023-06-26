#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Graph{
    public:
    unordered_map<T,list<T>> adjList;

    void addEdges(T u, T v, bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        //create an edge from u to v
        adjList[u].push_back(v);
        if(direction==0){
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout<<node.first<<" --> ";
            for(auto edge: node.second){
                cout<<edge<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int src,unordered_map<int, bool> &visited){
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";
            //Insert neighbour
            for(auto neighbour:adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(int i,unordered_map<int, bool> &visited){
        cout<<i<<" ";
        visited[i] = true;
        for(auto neighbour:adjList[i]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

    bool checkCycleUsingBfs(int src, unordered_map<int, bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto neighbour:adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                // if(visited[neighbour] && neighbour!=parent[frontNode]){
                //     //Already visited
                //     if(neighbour!=parent[frontNode]){
                //         //Cycle present
                //         return true;
                //     }
                // }
                else{
                    //Already visited
                    if(neighbour!=parent[frontNode]){
                        //Cycle present
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCycleUsingDfs(int src, unordered_map<int, bool> &visited, int parent){
        visited[src] = true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool aageKaAns = checkCycleUsingDfs(nbr,visited,src);
                if(aageKaAns) return true;
            }
            if(visited[nbr] && nbr!=parent){
                // Cycle present
                return true;
            }
        }
        return false;
    }

    bool checkCycleForDirectedGraphDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool aageKaAns = checkCycleForDirectedGraphDfs(nbr,visited,dfsVisited);
                if(aageKaAns==true) return true;
            }
            if(visited[nbr]==true && dfsVisited[nbr]==true){
                // Cycle present
                return true;
            }
        }
        // Backtracking ---> yahi pe galti hoti hai
        dfsVisited[src] = false;
        return false; 
    }
};

int main(){

    // Adjacency List
    Graph<int> g;
    int n = 5;
    // g.addEdges(0,1,0);
    // g.addEdges(1,3,0);
    // g.addEdges(0,2,0);
    // g.addEdges(2,4,0);

    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(2,3,1);
    g.addEdges(3,4,1);
    g.addEdges(4,0,1);

    bool ans = false;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans = g.checkCycleForDirectedGraphDfs(i,visited,dfsVisited);
            if(ans) break;
        }
    }
    if(ans) cout<<"Cycle is present"<<endl;
    else cout<<"Cycle is not present"<<endl;

    // unordered_map<int, bool> visited;
    // bool ans = false;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         ans = g.checkCycleUsingBfs(i,visited);
    //         if(ans==true){
    //             break;
    //         }
    //     }
    // }
    // if(ans) cout<<"Cycle is present"<<endl;
    // else cout<<"Cycle is not present"<<endl;


    // unordered_map<int, bool> visitedDfs;
    // bool dfsAns = false;
    // for(int i=0;i<n;i++){
    //     if(!visitedDfs[i]){
    //         dfsAns = g.checkCycleUsingDfs(i,visitedDfs,-1);
    //         if(dfsAns==true){
    //             break;
    //         }
    //     }
    // }
    // if(dfsAns) cout<<"Cycle is present"<<endl;
    // else cout<<"Cycle is not present"<<endl;

    

    // unordered_map<int, bool> visited;
    // run loop through all nodes
    // Handling for disconnected graph
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.bfs(i,visited);
    //     }
    // }
    // cout<<endl;
    // unordered_map<int, bool> visited2;
    // for(int i=0;i<n;i++){
    //     if(!visited2[i]){
    //         g.dfs(i,visited2);
    //     }
    // }

    // undirected graph
    // g.addEdges(0,1,0);
    // g.addEdges(1,2,0);
    // g.addEdges(0,2,0);
    // g.printAdjacencyList();

    // Directed graph
    // g.addEdges(0,1,1);
    // g.addEdges(1,2,1);
    // g.addEdges(0,2,1);
    // cout<<endl;
    // g.printAdjacencyList();


    // Adjacency Matrix
    // int n;
    // cout<<"Enter the number of nodes";
    // cin>>n;
    // vector<vector<int>> adj(n,vector<int>(n,0));
    // int e;
    // cout<<"Enter the number of edges";
    // cin>>e;
    
    // for(int i=0;i<e;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     // Mark 1
    //     adj[u][v]=1;
    // }

    // // Printing the matrix
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
