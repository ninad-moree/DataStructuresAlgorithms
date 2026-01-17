/*
    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common 
    subsequence, return 0.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) 
    deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.

    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.
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

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, text1, text2, dp);
    }
};
