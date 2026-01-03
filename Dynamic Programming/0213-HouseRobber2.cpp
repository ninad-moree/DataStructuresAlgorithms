/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place 
    are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected
    and it will automatically contact the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without 
    alerting the police.

    Example 1:
    Input: nums = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robTabulation(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = nums[0];
        
        for(int i=1; i<n; i++) {
            int pick = nums[i];
            if(i > 1)
                pick += dp[i-2];
            
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i=0; i<n; i++) {
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != n-1)
                temp2.push_back(nums[i]);
        }
            
        int ans1 = robTabulation(temp1);
        int ans2 = robTabulation(temp2);

        return max(ans1, ans2);
    }
};