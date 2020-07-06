#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int start = 0;
        for(int j=0; j< pow(2,n); j++) {
            vector<int> temp;
            for (int i=0; i<n; i++) {
                if(j & 1<<i)
                    temp.push_back(nums[i]);
            }
            result.push_back(temp);
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<int> input = {1, 2, 3};
    vector<vector<int>> output = s.subsets(input);
    for (auto vec : output) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    
}