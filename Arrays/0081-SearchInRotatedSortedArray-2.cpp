/*
    There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
    Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
    such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] 
    (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
    Given the array nums after the rotation and an integer target, return true if target is in nums, or false 
    if it is not in nums.
    You must decrease the overall operation steps as much as possible.

    Example 1:
    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int m = (l + r) / 2;

            if(nums[m] == target) 
                return true;

            if(nums[m] == nums[l]) {
                l++;
                continue;
            }

            if(nums[l] <= nums[m]) {
                if(nums[l] <= target && nums[m] > target)
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if(nums[r] >= target && nums[m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        
        return false;
    }
};