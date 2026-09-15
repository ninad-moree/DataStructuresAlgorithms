/*
    You are given a string s and a positive integer k. Select a set of non-overlapping substrings from the string s that satisfy the following conditions: The length of each 
    substring is at least k. Each substring is a palindrome. Return the maximum number of substrings in an optimal selection. A substring is a contiguous sequence of characters 
    within a string.

    Example 1:
    Input: s = "abaccdbbd", k = 3
    Output: 2
    Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
    It can be shown that we cannot find a selection with more than two valid substrings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, string s, int k, vector<vector<bool>>& isPal, vector<int>& dp) {
        if(idx >= s.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int notTake = solve(idx+1, s, k, isPal, dp);

        int take = 0;
        for(int j=idx + k - 1; j<s.size(); j++) {
            if(isPal[idx][j]) {
                take = max(take, 1 + solve(j+1, s, k, isPal, dp));
                break;
            }
        }

        return dp[idx] = max(take, notTake);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        // tells whether s[i..j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(s[i] == s[j]) {
                    if(j - i < 2)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        vector<int> dp(n, -1);

        return solve(0, s, k, isPal, dp);
    }
};