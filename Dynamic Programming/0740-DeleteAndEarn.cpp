/*
    You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times: Pick any nums[i] and 
    delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1. Return the maximum number of points
    you can earn by applying the above operation some number of times.

    Example 1:
    Input: nums = [3,4,2]
    Output: 6
    Explanation: You can perform the following operations: - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2]. - Delete 2 to earn 2 points. nums = [].
    You earn a total of 6 points.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx >= nums.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int currVal = nums[idx];
        int currSum = nums[idx];
        int nextIdx = idx + 1;

        while(nextIdx < nums.size() && nums[nextIdx] == currVal) {
            currSum += nums[idx];
            nextIdx++;
        }

        while(nextIdx < nums.size() && nums[nextIdx] == currVal + 1)
            nextIdx++;
        
        int take = currSum + solve(nextIdx, nums, dp);
        int notTake = solve(idx+1, nums, dp);

        return dp[idx] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        sort(nums.begin(), nums.end());

        return solve(0, nums, dp);
    }
};