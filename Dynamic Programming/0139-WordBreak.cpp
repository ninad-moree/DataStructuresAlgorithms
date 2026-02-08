/*
    Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.

    Example 1:
    Input: s = "leetcode", wordDict = ["leet","code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx, string s, vector<string>& wordDict, vector<int>& dp) {
        if(idx < 0)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(auto word : wordDict) {
            int size = word.size();

            if(idx - size + 1 < 0) 
                continue;

            if(s.substr(idx - size + 1, size) == word) {
                if(solve(idx - size, s, wordDict, dp))
                    return dp[idx] = 1;
            }
        }

        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s.size()-1, s, wordDict, dp);
    }
};