/*
    Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting
    substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character. For example, the underlined
    substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way. Return the number of substrings that satisfy the condition above. A substring
    is a contiguous sequence of characters within a string.

    Example 1:
    Input: s = "aba", t = "baba"
    Output: 6
    Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
    ("aba", "baba"), ("aba", "baba"), ("aba", "baba"), ("aba", "baba"), ("aba", "baba"), ("aba", "baba") The underlined portions are the substrings that are chosen from s and t.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string s, string t, bool diff, vector<vector<vector<int>>>& dp) {
        if(i == s.size() || j == t.size())
            return 0;
        
        if(dp[i][j][diff] != -1)
            return dp[i][j][diff];

        // Take
        if(diff == true) {
            if(s[i] != t[j])
                return dp[i][j][diff] = 0; // already diff of 1 is there 
            return dp[i][j][diff] = 1 + solve(i+1, j+1, s, t, diff, dp); // the char match take them
        }

        if(s[i] != t[j])
            return dp[i][j][diff] = 1 + solve(i+1, j+1, s, t, true, dp); // Take this first difference

        return dp[i][j][diff] = solve(i+1, j+1, s, t, diff, dp);  // Take equal characters
    }

    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));

        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<m; j++)
                ans += solve(i, j, s, t, false, dp);
        }

        return ans;
    }
};