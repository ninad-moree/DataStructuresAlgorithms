/*
    Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including
    zero). Otherwise, return false. There may be duplicates in the original array. Note: An array A rotated by x positions results in an array B of 
    the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

    Example 1:
    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i=1;i<n;i++) {
            if(nums[i-1] > nums[i]) 
                cnt++;
        }

        if(nums[n-1]>nums[0]) 
            cnt++;

        if(cnt>1) 
            return false;
        else 
            return true;
    }
};