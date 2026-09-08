/*
    You are given a string s consisting of lowercase English letters. A substring is almost-palindromic if it becomes a palindrome after removing exactly one character from it.
    Return an integer denoting the length of the longest almost-palindromic substring in s.

    Example 1:
    Input: s = "abca"
    Output: 4
    Explanation: Choose the substring "abca". Remove "abca". The string becomes "aba", which is a palindrome. Therefore, "abca" is almost-palindromic.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = solve(i+1, j-1, s, dp);
        
        return dp[i][j] = 1 + min(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
    }

    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int len = j - i + 1;

                if(len >= 2 && solve(i, j, s, dp) <= 1)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};