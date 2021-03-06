/*
BFS - queue!!
FIFO

Algorithm.


add root node to queue
while (queue not empty) {
    first = queue.frst
    visited(first)
    add all childen of first to queue.
    queue.dequeue()
}


*/

#include <vector>
#include <queue>
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
    
    void BFS() {
        vector<bool> discovered(adjList.size()+1, false);
        queue<int> q;
        int source;
        for(int i=1 ; i < adjList.size(); i++)
        {
            if(discovered[i] == false){ // discovered[6] => segmenation fault!
                q.push(i);
                discovered[i] = true;
                while(!q.empty())
                {
                    source = q.front();
                    for (auto child : adjList[source]){ // adjList[1,,,6] => segmentation fault!!
                        if(!discovered[child]){
                            q.push(child);
                            discovered[child] = true;
                        }
                    }
                    cout << q.front() << " ";
                    q.pop();
                }

            }
        }
    
    }
};


int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}}; // 1 5 8 10 100
		// vertex 0, 13 and 14 are single nodes


	// Number of nodes in the graph
	int N = 15;

	// create a graph from edges
	Graph graph(edges, N);
    graph.BFS();


	return 0;
}
