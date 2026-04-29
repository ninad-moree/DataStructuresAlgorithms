/*
    Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted. A string s is lexicographically 
    sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

    Example 1:
    Input: n = 1
    Output: 5
    Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int n, string vowels, vector<vector<int>>& dp) {
        if(n == 0)
            return 1;

        if(idx >= 5)
            return 0;

        if(dp[idx][n] != -1)
            return dp[idx][n];

        int pick = solve(idx, n-1, vowels, dp);
        int notPick = solve(idx+1, n, vowels, dp);

        return dp[idx][n] = pick + notPick;
    }

    int countVowelStrings(int n) {
        string vowels = "aeiou";
        vector<vector<int>> dp(5, vector<int>(n+1, -1));

        return solve(0, n, vowels, dp);
    }
};