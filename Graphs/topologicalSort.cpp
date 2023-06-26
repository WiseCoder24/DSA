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

    void topologicalSort(int i,unordered_map<int, bool> &visited,stack<int> &ans){
        visited[i] = true;
        for(auto neighbour:adjList[i]){
            if(!visited[neighbour]){
                topologicalSort(neighbour,visited,ans);
            }
        }
        // While returning store the node in stack
        ans.push(i);
    }

    void topoSortBfs(int n,vector<int> &ans){
        queue<int> q;
        unordered_map<int, int>indegree;

        // indegree calculation
        for(auto i: adjList){
            int src = i.first;
            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }
        //Put all the nodes with indegree==0 in queue
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        //bfs logic
        while(!q.empty()){
            int fNode = q.front();
            q.pop();
            ans.push_back(fNode);

            for(auto nbr:adjList[fNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
   

};

int main(){

    // Adjacency List
    Graph<int> g;
    int n = 4;
    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(2,3,1);
    g.addEdges(3,1,1);

    // g.addEdges(0,1,1);
    // g.addEdges(1,2,1);
    // g.addEdges(2,3,1);
    // g.addEdges(3,4,1);
    // g.addEdges(3,5,1);
    // g.addEdges(4,6,1);
    // g.addEdges(5,6,1);
    // g.addEdges(6,7,1);

    // unordered_map<int,bool> visited;
    // stack<int> ans;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.topologicalSort(i,visited,ans);
    //     }
    // }
    
    // while(!ans.empty()){
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }

    vector<int> ans;
    g.topoSortBfs(n,ans);
    
    // For cycle detection
    if(ans.size()==n) cout<<"Valid topo sort/Cycle is not present"<<endl;
    else cout<<"Invalid toposort/Cycle present"<<endl;

    for(auto i:ans){
        cout<<i<<" ";
    }

    cout<<endl;
}
