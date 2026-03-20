/*
    Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target. The test cases are generated so that the
    answer can fit in a 32-bit integer.

    Example 1:
    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    Note that different sequences are counted as different combinations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;

        if(dp[target] != -1)
            return dp[target];

        int ways = 0;
        for(auto i : nums)
            ways += solve(nums, target - i, dp);

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};