/*
    You are given an integer array nums and a non-negative integer k. In one operation, you can increase or decrease any element by 1.
    Return the minimum number of operations needed to make the median of nums equal to k.
    The median of an array is defined as the middle element of the array when it is sorted in non-decreasing order. If there are two 
    choices for a median, the larger of the two values is taken.

    Example 1:
    Input: nums = [2,5,6,8,5], k = 4
    Output: 2
    Explanation:
    We can subtract one from nums[1] and nums[4] to obtain [2, 4, 6, 8, 4]. The median of the resulting array is equal to k.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<int> nums1 = nums;

        int len = nums.size();
        int median = 0;
        int idx = 0;

        median = nums[len/2];
        idx = len/2;

        long long ans = 0;

        if(median == k)
            return ans;
        
        for(int i=0; i<=idx; i++) {
            if(nums[i] > k) 
                nums[i] = k;
        }

        for(int i=idx; i<nums.size(); i++) {
            if(nums[i] < k)
                nums[i] = k;
        }


        for(int i=0; i<nums.size(); i++) {
            ans += abs(nums[i] - nums1[i]);
        }

        return ans;
    }
};