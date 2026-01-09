/*
    You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To 
    partition nums, put each element of nums into one of the two arrays. Return the minimum possible absolute difference.

    Example 1:
    Input: nums = [3,9,7,3]
    Output: 2
    Explanation: One optimal partition is: [3,9] and [7,3]. The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(sum == 0)
            return dp[index][sum] = true;
        if(index == 0)
            return dp[index][sum] = (nums[index] == sum);

        if(dp[index][sum] != -1)
            return dp[index][sum];

        bool notTake = solve(index-1, sum, nums, dp);
        bool take = false;
        if(sum >= nums[index])
            take = solve(index-1, sum - nums[index], nums, dp);

        return dp[index][sum] = (take || notTake);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += i;

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        for (int s = 0; s <= sum; s++) 
            bool temp = solve(n - 1, s, nums, dp);

        int ans = INT_MAX;

        for(int i=0; i<=sum/2; i++) {
            if(dp[n-1][i] == true)
                ans = min(ans, abs((sum - i) - i));
        }

        return ans;
    }
};