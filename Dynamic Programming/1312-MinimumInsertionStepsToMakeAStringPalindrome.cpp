/*
    Given a string s. In one step you can insert any character at any index of the string. Return the minimum number of steps to make s palindrome. A Palindrome String is one 
    that reads the same backward as well as forward.

    Example 1:
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.
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

    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int temp = solve(n-1, n-1, s, t, dp);

        int longestPalindromeLen = dp[n-1][n-1];
        int len = s.size();

        return len - longestPalindromeLen;

    }
};