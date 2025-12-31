/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int open, int close, string str, vector<string>& ans) {
        if(2*n == str.size()) {
            ans.push_back(str);
            return;
        }

        if(open < n)
            solve(n, open + 1, close, str + '(', ans);

        if(close < open)
            solve(n, open, close + 1, str + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        int open = 0;
        int close = 0;

        solve(n, open, close, str, ans);

        return ans;
    }
};