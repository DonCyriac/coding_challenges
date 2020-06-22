/*
BFS - queue!!
FIFO

Algorithm.


for each node in graph if not visited then:
    push to stack and then mark as visited.
    push all non-visited children to stack.
    if there are no non- visited chidren then pop the top .
    push all non visited children of the current top of stack
}


*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Edge {
    int src;
    int dest;
};

class Graph {
    public:
    vector<vector<int>> adjList;

    Graph(vector<Edge>& edges,  int N) {
        adjList.resize(N+1); 
        for (Edge& edge: edges) {
            adjList[edge.src].push_back(edge.dest); 
            adjList[edge.dest].push_back(edge.src); 
        }
    }

    void postorder(vector<bool>& discovered, int source) {
        if(discovered[source]) return;

        discovered[source] = true;

        for (auto child: adjList[source]) {
            postorder(discovered, child);
        }

        cout << source << " ";
        return;        
    }

     void preorder(vector<bool>& discovered, int source) {
        if(discovered[source]) return;
        
        discovered[source] = true;
        cout << source << " ";

        for (auto child: adjList[source]) {
            preorder(discovered, child);
        }

        return;        
    }
    
    void DFS() {
        vector<bool> discovered(adjList.size()+1, false);

        cout << "POST ORDER:" << endl;
        postorder(discovered, 1);
        
        cout << "PRE ORDER:" << endl;
        discovered = vector<bool>(adjList.size()+1, false); 
        preorder(discovered, 1);
        // pre
    }    
};


int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}}; // 1 5 8 10 100
		// vertex 0, 13 and 14 are single nodes


	// Number of nodes in the graph
	int N = 12;

	// create a graph from edges
	Graph graph(edges, N);
    graph.DFS();


	return 0;
}
