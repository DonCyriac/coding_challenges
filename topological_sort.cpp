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
            // Directed
            adjList[edge.src].push_back(edge.dest);  
        }
    }
    
    void reverse(){
        int N = adjList.size();
        vector<vector<int>> temp; // [] [] [] [] [] 
        temp.resize(N+1);
        
        for (int src=0; src<N+1; src++) {
            for (int i=0; i < adjList[src].size(); i++) {
                int dest = adjList[src][i];
                temp[dest].push_back(src);
                // cout << "Dest=" << dest <<endl;
                // for(auto vertex: temp[dest])
                //     cout << vertex << endl;

                cout << "src=" << src << endl;
                cout << "i=" << i << endl;
                cout << "adjList[src].size() ==" << adjList[src].size() << endl;
                    // src = 7
                    // i= 1
            }
            cout<<"out";
        }
        cout << "lfsjdlkfjds";
        adjList = temp; // wrong!
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
    
    void topological_sort() {
        int N = adjList.size();
        vector<bool> discovered(N+1, false);
        vector<int> leaves;
        for(int src = 0; src < N+1; src++){
            if( adjList[src].size() == 0)
                leaves.push_back(src);
        }
        reverse();
        for(int leaf:leaves){
            postorder(discovered, leaf);
        }        
    }    
};


int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
		{5, 1}, {7, 0}, {7, 1}
	};

	// Number of nodes in the graph
	int N = 7;

	// create a graph from edges
	Graph graph(edges, N);
    graph.topological_sort();


	return 0;
}
