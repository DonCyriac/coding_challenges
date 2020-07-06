#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int countR = 0, countL = 0;
        int total_splits = 0;
        for(char c : s){
            if (c == 'R') countR++;
            else countL++;

            if (countL == countR) total_splits++;
        }
        return total_splits;
    }
};

int main() {
    Solution s;
    cout << s.balancedStringSplit("RLRRLLRLRL");
    return 0;
}