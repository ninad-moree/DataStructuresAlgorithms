/*
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target 
    exists, then return its index. Otherwise, return -1. You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l<=r) {
            int m = l + (r-l)/2;

            if(nums[m] ==  target)
                return m;
            else if(nums[m] < target) {
                l = m+1;
            } else
                r = m-1;
        }

        return -1;
    }
};