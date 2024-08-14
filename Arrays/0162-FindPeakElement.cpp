/*
    A peak element is an element that is strictly greater than its neighbors.
    Given a 0-indexed integer array nums, find a peak element, and return its index. 
    If the array contains multiple peaks, return the index to any of the peaks.
    You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always 
    considered to be strictly greater than a neighbor that is outside the array.
    You must write an algorithm that runs in O(log n) time.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int m = l + (h-l)/2;

        while(l < h) {
            if(nums[m] < nums[m+1])
                l = m+1;
            else
                h = m;

            m = l + (h-l)/2;
        }
        
        return l;
    }
};