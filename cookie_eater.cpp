#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // greed
        sort(s.begin(), s.end()); // size

        int last_eaten_cookie = -1, count = 0;
        for (auto greed : g){
            bool cookie_given = false;
            for(int i = last_eaten_cookie + 1; i < s.size(); i++)
            {
                if (s[i] >= greed) {
                    // satisfied
                    last_eaten_cookie = i;
                    count++;
                    cookie_given = true;
                    break;
                }
            }
            if(!cookie_given){
                break;
            }
        }

        return count;

    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}
