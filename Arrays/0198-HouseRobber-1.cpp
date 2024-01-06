/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
    the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
    it will automatically contact the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can 
    rob tonight without alerting the police.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prevPrev = 0;
        int prev = nums[0];


        for (int i = 1; i < n; ++i) {
            int current = max(prevPrev + nums[i], prev); 
            prevPrev = prev;
            prev = current;
        }

        return prev; 
    }
};