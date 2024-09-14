/*
    You are given an integer array nums of size n. Consider a non-empty subarray from nums that has the maximum possible bitwise AND. In other words, 
    let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered. 
    Return the length of the longest such subarray. The bitwise AND of an array is the bitwise AND of all the numbers in it. A subarray is a 
    contiguous sequence of elements within an array.

    Example 1:
    Input: nums = [1,2,3,3,2,2]
    Output: 2
    Explanation:
    The maximum possible bitwise AND of a subarray is 3.
    The longest subarray with that value is [3,3], so we return 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAnd = nums[0];

        for(int i=1; i<nums.size(); i++) 
            maxAnd = max(maxAnd, nums[i]);

        int ans = 1;
        int cnt = 0;
        int i = 0;

        while(i < nums.size()) {
            if(nums[i] == maxAnd) {
                while(i < nums.size() && nums[i] == maxAnd) {
                    cnt++;
                    i++;
                }

                ans = max(ans, cnt);
                cnt = 0;
            } else
                i++;
        }

        return ans;
    }
};