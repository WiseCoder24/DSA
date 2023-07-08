#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
	public:
	unordered_map<int, list<int >> adjList;

	void addEdge(int u, int v, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back(v);
		if(direction == 1) {
			adjList[v].push_back(u);
		}
	}

	

    void dfs1(int src,stack<int> &s, unordered_map<int,bool> &visited){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                dfs1(nbr,s,visited);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjNew){
        visited[src] = true;
        cout<<src<<", ";
        for(auto nbr: adjNew[src]){
            if(!visited[nbr]){
                dfs2(nbr,visited,adjNew);
            }
        }
    }

	int countSCC(int n){
        stack<int> s;
        unordered_map<int,bool> visited;
        // Topological order
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                dfs1(i,s,visited);
            }
        }

        //Reverse all edges
        unordered_map<int,list<int>> adjNew;
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u = t.first;
                int v = nbr;
                // insert v --> u
                adjNew[v].push_back(u);
            }
        }

        // Traverse using DFS
        int count = 0;
        unordered_map<int,bool> visited2;

        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited2[node]){
                cout<<"Printing "<<count+1<<"th SCC: ";
                dfs2(node,visited2,adjNew);
                cout<<endl; 
                count++;
            }
        }

        

        return count;

    }

    
    

};

int main() {
	graph g;

	
   g.addEdge(0,1,0);
   g.addEdge(1,2,0);
   g.addEdge(2,3,0);
   g.addEdge(3,0,0);
   g.addEdge(2,4,0);
   g.addEdge(4,5,0);
   g.addEdge(5,6,0);
   g.addEdge(6,4,0);
   g.addEdge(6,7,0);
   int ans = g.countSCC(8);
   cout<<"Number of SCC"<<ans<<endl;


    
	// g.floydWarshall(4);

	// stack<int> topoOrder;
	// unordered_map<int, bool> visited;
	// g.topoSortDfs(0, visited, topoOrder);

	

	// g.shortestpathDfs(3, topoOrder,5);
	
	

	// int src = 0;
	// // int dest = 4;

	// g.shortestPathBfs(src, dest);


	return 0;
}