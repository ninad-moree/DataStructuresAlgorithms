/*
    You are given a 0-indexed integer array nums.
    The low score of nums is the minimum value of |nums[i] - nums[j]| over all 0 <= i < j < nums.length.
    The high score of nums is the maximum value of |nums[i] - nums[j]| over all 0 <= i < j < nums.length.
    The score of nums is the sum of the high and low scores of nums.
    To minimize the score of nums, we can change the value of at most two elements of nums.
    Return the minimum possible score after changing the value of at most two elements of nums.

    Example 1:
    Input: nums = [1,4,3]
    Output: 0
    Explanation: Change value of nums[1] and nums[2] to 1 so that nums becomes [1,1,1]. Now, the value of |nums[i] - nums[j]| is always 
    equal to 0, so we return 0 + 0 = 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if(n==3)
            return 0;

        sort(nums.begin(), nums.end());

        return min(nums[n-1]-nums[2], min(nums[n-2]-nums[1], nums[n-3]-nums[0]));
    }
};