/*
    Given a binary array nums and an integer k, return the maximum number 
    of consecutive 1's in the array if you can flip at most k 0's.

    Example 1:
    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int zeros = 0;

        while(r < nums.size()) {
            if(nums[r] == 0)
                zeros++;

            if (zeros > k) {
                if(nums[l] == 0)
                    zeros--;
                l++;
            }

            if(zeros <= k) 
                ans = max(ans, r - l +1);
            
            r++;
        }

        return ans;
    }
};