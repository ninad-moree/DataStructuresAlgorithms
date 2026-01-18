/*
    Given two strings s and t, return the number of distinct subsequences of s which equals t. The test cases are generated so that the answer fits on a 32-bit signed integer.

    Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    rabbbit, rabbbit, rabbbit
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp) {
        if(idx2 == 0) 
            return 1;
        if(idx1 == 0) 
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(s[idx1-1] == t[idx2-1])
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, s, t, dp) + solve(idx1-1, idx2, s, t, dp);
        return dp[idx1][idx2] = solve(idx1-1, idx2, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, s, t, dp);
    }
};