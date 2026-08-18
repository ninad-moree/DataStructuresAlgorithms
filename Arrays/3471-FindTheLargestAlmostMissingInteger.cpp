/*
    You are given an integer array nums and an integer k. An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums. Return the largest
    almost missing integer from nums. If no such integer exists, return -1. A subarray is a contiguous sequence of elements within an array.

    Example 1:
    Input: nums = [3,9,2,1,7], k = 3
    Output: 7
    Explanation: 1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7]. 2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
    3 appears in 1 subarray of size 3: [3, 9, 2]. 7 appears in 1 subarray of size 3: [2, 1, 7]. 9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
    We return 7 since it is the largest integer that appears in exactly one subarray of size k.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size())
            return *max_element(nums.begin(), nums.end());

        vector<int> freq(51, 0);
        for(auto i : nums)
            freq[i]++;

        if(k == 1) {
            for(int i=50; i>=0; i--) {
                if(freq[i] == 1)
                    return i;
            }
        }

        int ans = -1;

        if(freq[nums[0]] == 1)
            ans = max(ans, nums[0]);
        
        if(freq[nums[nums.size()-1]] == 1)
            ans = max(ans, nums.back());

        return ans;
    }
};