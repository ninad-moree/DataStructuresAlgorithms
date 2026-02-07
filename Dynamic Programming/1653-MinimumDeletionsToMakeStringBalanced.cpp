/*
    You are given a string s consisting only of characters 'a' and 'b'​​​​. You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices 
    (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'. Return the minimum number of deletions needed to make s balanced.

    Example 1:
    Input: s = "aababbab"
    Output: 2
    Explanation: You can either:
    Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int isB, string& s, vector<vector<int>>& dp) {
        if(idx == s.size())
            return 0;

        if(dp[idx][isB] != -1)
            return dp[idx][isB];

        int ans = INT_MAX;

        if(s[idx] == 'a') {
            if(isB == 1)
                ans = 1 + solve(idx+1, isB, s, dp);
            else {
                int keepA = solve(idx+1, isB, s, dp);
                int deleteA = 1 + solve(idx+1, isB, s, dp);
                ans = min(keepA, deleteA);
            }
        } else {
            int keepB = solve(idx+1, 1, s, dp);
            int deleteB = 1 + solve(idx+1, isB, s, dp);
            ans = min(keepB, deleteB);
        }

        return dp[idx][isB] = ans;
    }

    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 0, s, dp);
    }
};