#include<unordered_map>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct Edge {
    int src;
    int dest;
};


class Compare
{
public:
    bool operator() (pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
    {
        
        return(b.second.first < a.second.first);
    }
};


class Graph {
    public:
    vector<vector<pair<int, int> >> adjList;

    Graph(int N) {
        adjList.resize(N+1); 
        for (int i = 1; i <= N ; i++) {
            // edge of weight 1 from start+1 to start+6
            for (int j=i+1; j<=100 && j<=i+6; j++) {
                adjList[i].push_back({j, 1});
            }
             // make_pair(x, y)
            // adjList[edge.dest].push_back(edge.src); 
        }
    }

    void addSnakes(unordered_map<int, int> &snake) {
        // head to tail 
        for(pair<int, int> s : snake){
            // head is s.first tail is s.second
            int head = s.first;
            int tail = s.second;
            adjList[head].clear();
            adjList[head].push_back({tail,0});
        }
    }

    void addLadders(unordered_map<int, int> &ladder) {
        // head to tail 
        for(pair<int, int> s : ladder){
            // head is s.first tail is s.second
            int bottom = s.first;
            int top = s.second;
            adjList[bottom].clear();
            adjList[bottom].push_back({top,0});
        }
    }
    
    int findSolution(int N) {
        // PQ stores the index of the vertex and its current known shortest distance
        priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, Compare> pq; // min pq  b  (a>b)  
        vector<bool> discovered(N+1, false);
        vector<int> distance(N+1, 1000000);
        vector<int> parent(N+1, 0);
        distance[1] = 0;

        for (int i=1; i<=100; i++) {
            pq.push({i, {distance[i], 0}});
        }
        
        int total_discovered = 0;
        // cout << pq.top().first << " " << pq.top().second << "\n";
        while(total_discovered<100){
            pair<int, pair<int, int>> smallest = pq.top();
            if(discovered[smallest.first]){
                pq.pop();
                continue;
            }
            discovered[smallest.first]=true;
            pq.pop();
            distance[smallest.first]=smallest.second.first;
            parent[smallest.first] = smallest.second.second;
            if(smallest.first == 100) break;
            for(auto child : adjList[smallest.first]){
                pq.push({child.first,{distance[smallest.first]+child.second,smallest.first}});
            }
            total_discovered += 1;
        }
        // do stuff while some nodes are not visited

        int start = 100;
        while(start != 1){
            cout << start << " " << endl;
            start = parent[start];
        }
        return distance[100];
    }
};



int main()
{
	// snakes and ladders are represented using a map
	unordered_map<int, int> ladder, snake;
    Graph g(100);
	// insert ladders into the map
	// ladder[1] = 38;
	ladder[4] = 14;
	ladder[9] = 31;
	ladder[21] = 42;
	ladder[28] = 84;
	ladder[51] = 67;
	ladder[72] = 91;
	ladder[80] = 99;

	// insert snakes into the map
	snake[17] = 7;
	snake[54] = 34;
	snake[62] = 19;
	snake[64] = 60;
	snake[87] = 36;
	snake[93] = 73;
	snake[95] = 75;
	snake[98] = 79;
    
    g.addLadders(ladder);
    g.addSnakes(snake);
	cout << g.findSolution(100) << endl;

	return 0;
}