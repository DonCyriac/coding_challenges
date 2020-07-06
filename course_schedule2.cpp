#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        vector<bool> discovered(graph.size(), false);
        for (vector<int>& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> visited;


        for (int i=0; i<numCourses; i++) {
            postorder(discovered, i, visited, graph);
        }

        vector<int> reversed;
        for (auto itr=visited.rbegin(); itr != visited.rend(); itr++) {
            reversed.push_back(*itr);
        }

        return reversed;
    }
    void postorder(vector<bool>& discovered, int source, vector<int>& visited, vector<vector<int>> graph) {
        if(discovered[source]) return;

        discovered[source] = true;
        visited.push_back(source);

        for (auto child: graph[source]) {
            postorder(discovered, child, visited, graph);
        }
        return;        
    }
};