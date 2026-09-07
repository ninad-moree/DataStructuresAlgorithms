/*
    Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7. A subsequence of a string is a 
    new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
    (i.e., "ace" is a subsequence of "abcde" while "aec" is not.

    Example 1:
    Input: s = "abc"
    Output: 7
    Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int idx, string& s, vector<int>& dp) {
        if(idx >= s.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        vector<int> vis(26);

        int ans = 0;

        for(int i=idx; i<s.size(); i++) {
            if(vis[s[i] - 'a'])
                continue;

            vis[s[i] - 'a'] = 1;
            ans = (ans + 1 + solve(i+1, s, dp)) % MOD;
        }

        return dp[idx] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};