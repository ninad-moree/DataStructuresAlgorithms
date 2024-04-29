/*
    You are given a 0-indexed integer array nums, and an integer k.
    The K-or of nums is a non-negative integer that satisfies the following:
    The ith bit is set in the K-or if and only if there are at least k elements of nums in which bit i is set.
    Return the K-or of nums.
    Note that a bit i is set in x if (2i AND x) == 2i, where AND is the bitwise AND operator.

    Example 1:
    Input: nums = [7,12,9,8,9,15], k = 4
    Output: 9
    Explanation: Bit 0 is set at nums[0], nums[2], nums[4], and nums[5].
    Bit 1 is set at nums[0], and nums[5].
    Bit 2 is set at nums[0], nums[1], and nums[5].
    Bit 3 is set at nums[1], nums[2], nums[3], nums[4], and nums[5].
    Only bits 0 and 3 are set in at least k elements of the array, and bits i >= 4 are not set in any of the array's elements. 
    Hence, the answer is 2^0 + 2^3 = 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int cnt = 0;

            for (int num : nums) {
                if ((num & (1 << i)) != 0) 
                    cnt++;
            }

            if (cnt >= k) 
                ans |= (1 << i);
        }

        return ans;
    }
};