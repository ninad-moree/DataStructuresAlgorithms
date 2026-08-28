/*
    You are given an integer array nums of length n and a binary string s of length n, where s[i] == '1' means index i initially contains a token and s[i] == '0' means it does 
    not.  You may perform the following operation any number of times: Choose a token currently located at index i, where i > 0, such that this token has not been moved before.
    Move this token from index i to index i - 1. An index is considered covered if it contains a token after all moves. Return an integer denoting the maximum total value of 
    nums at the covered indices after optimally performing the operations.

    Example 1:
    Input: nums = [9,2,6,1], s = "0101"
    Output: 15
    Explanation: Initially, indices 1 and 3 contain tokens. Move the token from index 3 to index 2. Move the token from index 1 to index 0.
    The covered indices are [0, 2], so the total value is nums[0] + nums[2] = 9 + 6 = 15.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int idx, int canMove, vector<int>& nums, string& s, vector<vector<long long>>& dp) {
        if(idx == 0) {
            if(s[idx] == '1' && !canMove)
                return nums[0];
            return 0;
        }
           
        if(dp[idx][canMove] != -1)
            return dp[idx][canMove];

        if(s[idx] == '0')
            return dp[idx][canMove] = solve(idx-1, 0, nums, s, dp);

        long long take1 = 0;
        if(canMove != 1)
            take1 = nums[idx] + solve(idx-1, 0, nums, s, dp);

        long long take2 = nums[idx-1] + solve(idx-1, 1, nums, s, dp);

        return dp[idx][canMove] = max(take1, take2);
    }

    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(n-1, 0, nums, s, dp);
    }
};
