/*
    You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
    "1" -> 'A'
    "2" -> 'B'
    ...
    "25" -> 'Y'
    "26" -> 'Z'
    However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" 
    vs "25"). For example, "11106" can be decoded into: "AAJF" with the grouping (1, 1, 10, 6) OR "KJF" with the grouping (11, 10, 6) The grouping (1, 11, 06) is invalid 
    because "06" is not a valid code (only "6" is valid). Note: there may be strings that are impossible to decode. Given a string s containing only digits, return the number 
    of ways to decode it. If the entire string cannot be decoded in any valid way, return 0. The test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:
    Input: s = "12"
    Output: 2
    Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s, int idx, vector<int>& dp) {
        if(idx == s.size())
            return 1;
        
        if(s[idx] == '0')
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int singleD = solve(s, idx+1, dp);

        int doubleD = 0;
        if(idx + 1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))) 
            doubleD = solve(s, idx+2, dp);

        return dp[idx] = singleD + doubleD;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);

        return solve(s, 0, dp);
    }
};