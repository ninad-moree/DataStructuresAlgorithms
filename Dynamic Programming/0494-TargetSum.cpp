/*
    You are given an integer array nums and an integer target. You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums 
    and then concatenate all the integers. For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.

    Example 1:
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(index == 0) {
            if(target == 0 && nums[index] == 0)
                return 2;
            if(target == 0 || nums[index] == target)
                return 1;
            return 0;
        }

        if(dp[index][target] != -1)
            return dp[index][target];

        int notTake = solve(index-1, target, nums, dp);
        int take = 0;
        if(target >= nums[index])
            take = solve(index-1, target - nums[index], nums, dp);

        return dp[index][target] = (take + notTake);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum - target < 0 || (sum-target)%2 == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>((sum-target)/2+1, -1));

        return solve(n-1, (sum-target)/2, nums, dp);
    }
};