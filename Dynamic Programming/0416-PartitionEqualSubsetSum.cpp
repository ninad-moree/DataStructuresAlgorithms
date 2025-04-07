/*
    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal
    or false otherwise.

    Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;

        if(sum%2 != 0)
            return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) 
                dp[i] = dp[i] || dp[i - num];
        }

        return dp[target];
    }
};