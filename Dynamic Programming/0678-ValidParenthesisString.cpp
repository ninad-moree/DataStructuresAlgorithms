/*
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid. The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'. Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an 
    empty string "".

    Example 1:
    Input: s = "(*))"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s, int idx, int cnt, vector<vector<int>>& dp) {
        if(cnt < 0)
            return false;
        if(idx == s.size())
            return cnt == 0;
        
        if(dp[idx][cnt] != -1)
            return dp[idx][cnt];

        if(s[idx] == '(')
            return dp[idx][cnt] = solve(s, idx+1, cnt+1, dp);
        if(s[idx] == ')')
            return dp[idx][cnt] = solve(s, idx+1, cnt-1, dp);
        
        return dp[idx][cnt] = solve(s, idx+1, cnt+1, dp) || solve(s, idx+1, cnt-1, dp) || solve(s, idx+1, cnt, dp);
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, 0, 0, dp);
    }
};