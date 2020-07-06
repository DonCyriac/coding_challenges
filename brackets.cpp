#include<stack>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> brackets;
        for(char c : S){
            if( c == '(')
                brackets.push(c);
            else if( c == ')') {
                if (brackets.empty() || brackets.top() != '(') {
                    brackets.push(c);
                }
                else {
                    brackets.pop();
                }
            }
        }
        cout << brackets.size();
        return brackets.size();

    }
};

int main() {
    Solution s;
    string v = "())";
    s.minAddToMakeValid(v);
    return 0;
}