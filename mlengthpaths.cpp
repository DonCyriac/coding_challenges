#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int src;
    int dest;
};

class Graph {
    public:
    
    vector<vector<int> > adjList;

    Graph(vector<Edge>& edges, int N) {
        adjList.resize(N+1);
        for (Edge edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }

   int bfs(int start, int m, int dest) {
        int len = 0;
        queue<pair<int, int>> q;
        vector<bool> discovered(adjList.size());
        int count = 0;
        q.push({start, 0});
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int idx = curr.first;
            int level = curr.second;

            if (level > m) {
                return count;
            }

            discovered[idx] = true;
            q.pop();
            if (idx == dest && level == m) {
                count++;
            }


            for (int child: adjList[idx]) {
                q.push({child, level+1});
            }
        }

        return count;
    }
};


int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
		{5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
	};



	// Number of nodes in the graph
	int N = 7;

	// create a graph from edges
	Graph graph(edges, N);
    cout << graph.bfs(0,4,3) << endl;


	return 0;
}