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

    bool check_bipartite(vector<int>& discovered, int source, int parent_color) {
        if(discovered[source] == parent_color) return false;

        if (discovered[source]) return true;
    
        discovered[source] = (parent_color == 1) ? 2 : 1;


        for (auto child: adjList[source]) {
            if (!check_bipartite(discovered, child, discovered[source])) return false;
        }

        return true;     
    }

    void DFS() {
        vector<int> discovered(adjList.size()+1, 0);

        if (check_bipartite(discovered, 1, 2))
            cout << "Graph is bipartite" << endl;
        else
            cout << "Graph is not bipartite" << endl;
        
    }    
};




bool check(vector<vector<int>>& graph, vector<int>& discovered, int source, int parent_color) {
    if(discovered[source] == parent_color) return false;

    if (discovered[source]) return true;

    discovered[source] = (parent_color == 1) ? 2 : 1;


    for (auto child: graph[source]) {
        if (!check(graph, discovered, child, discovered[source])) return false;
    }

    return true;     
}



bool isBipartite(vector<vector<int>>& graph) {
    vector<int> discovered(graph.size(), 0);


}






int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {2, 3}, {3, 4}, {1, 4}}; // 1 5 8 10 100
		// vertex 0, 13 and 14 are single nodes


	// Number of nodes in the graph
	int N = 4;

	// create a graph from edges
	Graph graph(edges, N);
    graph.DFS();


	return 0;
}
