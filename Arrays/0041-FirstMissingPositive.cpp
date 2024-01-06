/*
    Given an unsorted integer array nums, return the smallest missing positive integer.
    You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

    Example 1:
    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) 
                nums[i] = n + 1;
        }

        for (int i = 0; i < n; ++i) {
            int val = abs(nums[i]);
            if (val <= n) 
                nums[val - 1] = -abs(nums[val - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) 
                return i + 1;
        }

        return n + 1;
    }
};