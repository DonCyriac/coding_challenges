#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> groups;
        vector<int> map(n+1, -1); // 3 group map[3] == -1 -> idx  ->  groups[idx]


        for (int i=0; i<groupSizes.size(); i++) {
            if (map[groupSizes[i]] == -1) { // invariant: map with -1 has no group ready
                map[groupSizes[i]] = groups.size();
                groups.push_back(vector<int>());
                groups[map[groupSizes[i]]].push_back(i);
                
            } else {
                // already a partially filled group present
                groups[map[groupSizes[i]]].push_back(i);
            }

            if (groups[map[groupSizes[i]]].size() == groupSizes[i]) {
                // filled ; reset map
                map[groupSizes[i]] = -1;
            }

            
        }
        for(auto group : groups){
            for(auto element : group){
                cout << element << " ";
            }
            cout << endl;
        }

        return groups;
        


    }
};


int main() {
    Solution s;
    vector<int> v = {3,3,3,3,3,1,3};
    s.groupThePeople(v);
    return 0;
}

