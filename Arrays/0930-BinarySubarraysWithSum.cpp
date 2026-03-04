/*
    Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
    A subarray is a contiguous part of the array.

    Example 1:
    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4 
    (1,0,1) (0,1,0) (0,1,0,1) (1,0,1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;

        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;

        while(r < nums.size()) {
            sum += nums[r];

            while(sum > goal) {
                sum -= nums[l];
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};