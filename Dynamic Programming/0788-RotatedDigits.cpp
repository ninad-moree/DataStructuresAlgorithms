/*
    An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose
    to leave it alone. A number is valid if each digit remains a digit after rotation. For example:
    0, 1, and 8 rotate to themselves, 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
    6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
    Given an integer n, return the number of good integers in the range [1, n].

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9. Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotMap = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

    int solve(int pos, bool bound, bool changed, bool valid, string digits, vector<vector<vector<vector<int>>>>& dp) {
        if(!valid)
            return 0;
        
        if(pos == digits.size()) 
            return (valid && changed) ? 1 : 0;

        if(dp[pos][bound][changed][valid] != -1)
            return dp[pos][bound][changed][valid];

        int limit = bound ? (digits[pos] - '0') : 9;
        int count = 0;
        
        for (int d = 0; d <= limit; d++) {
            int rotated = rotMap[d];
            if (rotated == -1) 
                continue; 
            
            bool newChanged = changed || (rotated != d);
            bool newBound = bound && (d == limit);
            
            count += solve(pos + 1, newBound, newChanged, true, digits, dp);
        }
        
        return dp[pos][bound][changed][valid] = count;
    }

    int rotatedDigits(int n) {
        string digits = to_string(n);
        vector<vector<vector<vector<int>>>> dp(11, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
        
        return solve(0, true, false, true, digits, dp);
    }
};