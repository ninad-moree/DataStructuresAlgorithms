/*
    An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same. For example, 
    [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences. Given an integer array nums, return the number of arithmetic subarrays of nums. A subarray is a contiguous
    subsequence of the array. 

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 3
    Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int prevIdx, int diff,  vector<int>& nums) {
        if(idx == nums.size() || nums[idx] - nums[prevIdx] != diff)
            return 0;

        return 1 + solve(idx+1, idx, diff, nums);
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n < 3)
            return 0;

        int ans = 0;

        for(int i=0; i<n-2; i++) {
            int diff = nums[i+1] - nums[i];
            ans += solve(i+2, i+1, diff, nums);
        }

        return ans;
    }
};