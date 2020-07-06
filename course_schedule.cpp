#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int root, vector<bool>& discovered, vector<vector<int>>& graph) {
        if (discovered[root]) {
            return false;
        }

        discovered[root] = true;

        for (int child: graph[root]) {
            if (!dfs(child, discovered, graph))
                return false;
        }
        discovered[root] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        vector<bool> discovered(graph.size(), false);
        for (vector<int>& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < discovered.size() ; i++){
            if(!discovered[i] && !dfs(i, discovered, graph))
                return false;
        }
        return true;
    }
};


int main() {
    Solution.
    Solution.canFinish(2, [[1,0]]);
    return 0;
}