/*
    Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2. An interleaving of two strings s and t is a configuration where s and t are 
    divided into n and m substrings respectively, such that: s = s1 + s2 + ... + sn, t = t1 + t2 + ... + tm, |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ... Note: a + b is the concatenation of strings a and b.

    Example 1:
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: true
    Explanation: One way to obtain s3 is:
    Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a". Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
    Since s3 can be obtained by interleaving s1 and s2, we return true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx1, int idx2, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (idx1 == s1.size() && idx2 == s2.size())
            return 1;

        int idx3 = idx1 + idx2;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        int result = 0;

        if (idx1 < s1.size() && s1[idx1] == s3[idx3])
            result = solve(idx1 + 1, idx2, s1, s2, s3, dp);

        if (!result && idx2 < s2.size() && s2[idx2] == s3[idx3])
            result = solve(idx1, idx2 + 1, s1, s2, s3, dp);

        return dp[idx1][idx2] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size()) 
            return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, s1, s2, s3, dp);
    }
};