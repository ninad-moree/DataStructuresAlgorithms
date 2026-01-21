/*
    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx1, int idx2, string& s, string& p, vector<vector<int>>& dp) {
        if(idx1 < 0 && idx2 < 0)
            return true;
        if(idx2 < 0 && idx1 >= 0)
            return false;
        if(idx1 < 0 && idx2 >= 0) {
            for(int i=0; i<=idx2; i++) {
                if(p[i] != '*')
                    return false;
            }
            return true;
        }

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(s[idx1] == p[idx2] || p[idx2] == '?')
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, s, p, dp);
        if(p[idx2] == '*')
            return dp[idx1][idx2] = (solve(idx1, idx2-1, s, p, dp) || solve(idx1-1, idx2, s, p, dp));
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, s, p, dp);
    }
};