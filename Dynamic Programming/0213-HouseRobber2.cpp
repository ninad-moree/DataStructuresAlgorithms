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
    int solve(vector<int> nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1) 
            return nums[0];

        int prev = 0;
        int temp = nums[0];

        for(int i=1; i<n; i++) {
            int curr = max(prev + nums[i], temp);
            prev = temp;
            temp = curr;
        }

        return temp;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];

        vector<int> a1(nums.size()-1);
        for(int i=0; i<nums.size()-1; i++) 
            a1[i] = nums[i];

        vector<int> a2(nums.size()-1);
        for(int i=1; i<nums.size(); i++) 
            a2[i-1] = nums[i];

        int c1 = solve(a1);
        int c2 = solve(a2);

        return max(c1, c2);
    }
};