/*
    Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
    Return the positive integer k. If there is no such integer, return -1.

    Example 1:
    Input: nums = [-1,2,-3,3]
    Output: 3
    Explanation: 3 is the only valid k we can find in the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size()-1;

        while(l<r) {
            if(nums[l] + nums[r] == 0)
                return nums[r];
            else if( abs(nums[l]) < abs(nums[r]) )
                r--;
            else
                l++;
        }

        return -1;
    }
};