/*
    Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string. Return a list of all possible strings we could create. 
    Return the output in any order.

    Example 1:
    Input: s = "a1b2"
    Output: ["a1b2","a1B2","A1b2","A1B2"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, string s, vector<string>& ans, string res) {
        if(idx == s.size()) {
            ans.push_back(res);
            return;
        }

        if(isalpha(s[idx])) {
            res += tolower(s[idx]);
            solve(idx + 1, s, ans, res);
            res.pop_back();

            res += toupper(s[idx]);
            solve(idx + 1, s, ans, res);
            res.pop_back();
        } else {
            res += s[idx];
            solve(idx + 1, s, ans, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(0, s, ans, "");

        return ans;
    }
};