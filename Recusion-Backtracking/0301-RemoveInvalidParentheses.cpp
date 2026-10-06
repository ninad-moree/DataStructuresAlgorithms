/*
    Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid. Return a list of unique strings that
    are valid with the minimum number of removals. You may return the answer in any order.

    Example 1:
    Input: s = "()())()"
    Output: ["(())()","()()()"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, string& s, set<string>& st, string& res, int& open, int& close, int& maxLen) {
        if(idx == s.size()) {
            if(open == close) {
                if(res.size() > maxLen) {
                    st.clear();
                    maxLen = res.size();
                    st.insert(res);
                } else if(res.size() == maxLen)
                    st.insert(res);
            }
            return;
        }

        res += s[idx];
        if(s[idx] == '(')
            open++;
        else if(s[idx] == ')') {
            if(open > close)
                close++;
            else {
                res.pop_back(); // invalid ')'
                solve(idx+1, s, st, res, open, close, maxLen); // skip invalid ')' and move forward
                return;
            }
        }

        solve(idx+1, s, st, res, open, close, maxLen); // take the valid ')' and move forward

        // backtrack
        if(res.back() == '(')
            open--;
        else if(res.back() == ')')
            close--;
        res.pop_back();

        solve(idx+1, s, st, res, open, close, maxLen); // don't take the current character
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        set<string> st;
        string res = "";
        int open = 0;
        int close = 0;
        int maxLen = 0;

        solve(0, s, st, res, open, close, maxLen);

        for(auto i : st)
            ans.push_back(i);

        return ans;
    }
};