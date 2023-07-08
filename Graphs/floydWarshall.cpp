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
	unordered_map<int, list<pair<int,int> > > adjList;

	void addEdge(int u, int v, int wt, bool direction) {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		unordered_map<int,bool> visited;
		unordered_map<int,int> parent;

		//inital steps for src
		q.push(src);
		visited[src] = 1;
		parent[src] = -1;

		while(!q.empty()) {
			int fNode = q.front();
			q.pop();

			for(auto nbr: adjList[fNode]) {
				if(!visited[nbr.first]) {
					q.push(nbr.first);
					visited[nbr.first] = 1;
					parent[nbr.first] = fNode;
				}
			}
		}

		//store path in ans, after traversing in the parent array
		vector<int> ans;
		int node = dest;
		while(node != -1) {
			ans.push_back(node);
			node = parent[node];
		}

		reverse(ans.begin(), ans.end());

		cout << "printing ANs: " << endl;
		for(auto i: ans) {
			cout << i<<", ";
		}
		cout << endl;
		
	}


	void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: adjList[src]) {
			if(!visited[neighbour.first] ) {
				topoSortDfs(neighbour.first, visited, ans);
			}
		}

		//while returning, store the node in stack
		cout << "Pushing " << src << endl;
		ans.push(src);
	}

 	void shortestpathDfs(int dest, stack<int> topoOrder, int n) {
		vector<int> dist(n, INT_MAX);

		int src = topoOrder.top();
		topoOrder.pop();
		dist[src] = 0;


		for(auto nbr: adjList[0]) {
			if(dist[0] + nbr.second < dist[nbr.first]) {
				dist[nbr.first] = dist[0] + nbr.second;
			}
		}		
			

		while(!topoOrder.empty()) {

			int topElement = topoOrder.top();
			topoOrder.pop();

			if(dist[topElement] != INT_MAX) {
				for(auto nbr: adjList[topElement]) {
					if(dist[topElement] + nbr.second < dist[nbr.first]) {
						dist[nbr.first] = dist[topElement] + nbr.second;
					}
				}
			}
		}

		cout << "Printing Ans: " << endl;
		for(int i=0; i<n; i++) {
			cout << i <<"-> " << dist[i] << endl;
		}
		
		
	}

	void floydWarshall(int n){
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        // Diagonal pe 0 mark karo
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        // Graph ke according distance insert karo
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;

            }
        }

        for(int helper = 0;helper<n;helper++){
            for(int src = 0;src<n;src++){
                for(int dest = 0;dest<n;dest++){
                    dist[src][dest] = min(dist[src][dest],dist[src][helper]+dist[helper][dest]);
                }
            }
        }

        cout<<"Printing distance array:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<", ";
            }cout<<endl;
        }

    }

    
    

};

int main() {
	graph g;

	
    g.addEdge(0,1,3,0);
    g.addEdge(0,3,5,0);
    g.addEdge(1,0,2,0);
    g.addEdge(1,3,4,0);
    g.addEdge(2,1,1,0);
    g.addEdge(3,2,2,0);

	g.printAdjList();
    
	g.floydWarshall(4);

	// stack<int> topoOrder;
	// unordered_map<int, bool> visited;
	// g.topoSortDfs(0, visited, topoOrder);

	

	// g.shortestpathDfs(3, topoOrder,5);
	
	

	// int src = 0;
	// // int dest = 4;

	// g.shortestPathBfs(src, dest);


	return 0;
}