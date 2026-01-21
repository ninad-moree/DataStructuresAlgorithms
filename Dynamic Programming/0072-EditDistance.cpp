/*
    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2. You have the following three operations permitted on a word:
    Insert a character
    Delete a character
    Replace a character

    Example 1:
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx1, int idx2, string& w1, string& w2, vector<vector<int>>& dp) {
        if(idx1 < 0)
            return idx2 + 1;
        if(idx2 < 0)
            return idx1 + 1;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(w1[idx1] == w2[idx2])
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, w1, w2, dp);

        int insert = 1 + solve(idx1, idx2-1, w1, w2, dp);
        int deletei = 1 + solve(idx1-1, idx2, w1, w2, dp);
        int replace = 1 + solve(idx1-1, idx2-1, w1, w2, dp);

        return dp[idx1][idx2] = min(insert, min(deletei, replace));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n-1, m-1, word1, word2, dp);
    }
};