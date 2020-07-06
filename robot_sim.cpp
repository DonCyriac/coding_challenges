#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:

    pair<int, int> add_coords(pair<int, int>& a, pair<int, int>& b) {
        return {a.first + b.first, a.second + b.second};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int, int> RIGHT = {1, 0};
        pair<int, int> LEFT = {-1, 0};
        pair<int, int> UP = {0, 1};
        pair<int, int> DOWN = {0, -1};
        
        set<pair<int, int>> obs_set;

        for(auto obstacle : obstacles){
            obs_set.insert({obstacle[0],obstacle[1]});
        }


        vector<pair<int, int>> DIRECTIONS = {UP, RIGHT, DOWN, LEFT};
        int sign = 1;
        int direction_idx = 0;
        
        pair<int, int> current_pos = {0, 0};
        int max_distance = -1;
        for (int command : commands) {
            if (command == -2) {
                direction_idx =((direction_idx+4)-1)%4;
            }
            else if (command == -1) {
                direction_idx =(direction_idx+1)%4;
            }
            else if (1 <= command && command <= 9) {
                for(int i = 0; i < command; i++)
                {
                    pair<int, int> new_coord = add_coords(current_pos, DIRECTIONS[direction_idx]);
                    auto search = obs_set.find(new_coord);
                    if (search != obs_set.end()) { // obstacle present
                        break;
                    }
                    current_pos = new_coord;
                    
                }
                int new_distance = current_pos.first*current_pos.first + current_pos.second*current_pos.second;
                if (new_distance > max_distance)
                    max_distance = new_distance;    
            }
        }

        // here!
        return max_distance;
        
    }
};

int main() {
    Solution s;
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    
    cout << s.robotSim(commands,obstacles) << endl;
    return 0;
}
