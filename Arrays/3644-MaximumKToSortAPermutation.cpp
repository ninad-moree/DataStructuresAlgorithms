/*
    You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [0..n - 1]. You may swap elements at indices i and j only if 
    nums[i] AND nums[j] == k, where AND denotes the bitwise AND operation and k is a non-negative integer. Return the maximum value of k such that the array can be sorted in 
    non-decreasing order using any number of such swaps. If nums is already sorted, return 0.

    Example 1:
    Input: nums = [0,3,2,1]
    Output: 1
    Explanation:
    Choose k = 1. Swapping nums[1] = 3 and nums[3] = 1 is allowed since nums[1] AND nums[3] == 1, resulting in a sorted permutation: [0, 1, 2, 3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i)
                ans = ans & nums[i];
        }

        return ans == -1 ? 0 : ans;
    }
};