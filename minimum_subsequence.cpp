#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        int seq = 0;
        vector<int> subseq;
        // std::nth_element(nums.begin(), v.begin()+1, v.end(), std::greater<int>());
        int i=0;
        while(seq <= (sum - seq)){
            std::nth_element(nums.begin(), nums.begin()+i, nums.end(), std::greater<int>());
            seq = seq + nums[i];

            subseq.push_back(nums[i]);
            i++;
        }
        // (auto i : subseq)
        //     cout << i << " ";
        return subseq;
    }
};



int main() {
    Solution s;
    vector<int> v = {3, 5, 2, 1};
    s.minSubsequence(v);

    return 0;
}

