#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_idx(30, -1);
        vector<int> result;

        for (int i=0; i<S.size(); i++) {
            last_idx[S[i]-'a'] = i;
        }

        int partition_start = 0;
        int end_partition_idx = 0;
        //ab<--abcbaca(8)<------   defegdehijhklij
        for(int idx = 0; idx < S.size(); idx++){
            if(last_idx[S[idx]-'a'] > end_partition_idx ) {
                end_partition_idx = last_idx[S[idx]-'a'];
            }
            
            if (idx == end_partition_idx) {
                result.push_back(idx - partition_start + 1);
                partition_start = idx + 1;
                end_partition_idx++;
            }

        }
        for(int size : result)
        {
            cout << size << " ";
        }
        cout << endl;
        return result;
        
        
    }
};



int main() {
    Solution s;
    string v = "ababcbacadefegdehijhklij";
    s.partitionLabels(v);
    return 0;
}

