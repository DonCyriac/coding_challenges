#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0;
        int odd = 0;
        for (int i=0; i<chips.size(); i++) {
            if (chips[i]%2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }
        cout << "blahs";
        return min(even, odd);
        
    }
};



int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    cout << s.minCostToMoveChips(v) << endl;
    return 0;
}

