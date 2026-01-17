/*
    Given a string s, find the longest palindromic subsequence's length in s. A subsequence is a sequence that can be derived from another sequence by deleting some or no 
    elements without changing the order of the remaining elements.

    Example 1:
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
        if(idx1 < 0 || idx2 < 0)
            return 0;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2])
            return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
        return dp[idx1][idx2] = max(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(n-1, n-1, s, t, dp);
    }
};