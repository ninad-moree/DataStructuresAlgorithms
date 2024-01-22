/*
    You are given an integer array nums where the largest integer is unique.
    Determine whether the largest element in the array is at least twice as much as every other number in the array. 
    If it is, return the index of the largest element, or return -1 otherwise.

    Example 1:
    Input: nums = [3,6,1,0]
    Output: 1
    Explanation: 6 is the largest integer.
    For every other number in the array x, 6 is at least twice as big as x.
    The index of value 6 is 1, so we return 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = nums[0];
        int max2 = -1;
        int ans = 0;

        for(int i=1;i<nums.size();i++) {
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                ans = i;
            } 
            else if (nums[i] > max2)
                max2 = nums[i];
        }

        if(max2*2 > max1)
            return -1;
        return ans;
    }
};