/*
    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either 
    string.

    Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* MEMORIZATION */
    int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
        if(idx1 < 0 || idx2 < 0)
            return 0;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2])
            return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
        return dp[idx1][idx2] = max(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int temp = solve(n-1, m-1, word1, word2, dp);
        int LCS = dp[n-1][m-1];

        int ans = n + m - 2*LCS;

        return ans;
    }
};