/*
    You are given an array of integers nums. Return the length of the longest subarray of nums which is either 
    strictly increasing or strictly decreasing.

    Example 1:
    Input: nums = [1,4,3,3,2]
    Output: 2
    Explanation:
    The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
    The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;

        for(int i=1; i<nums.size(); i++) {
            int len = 1;
            for(int j=i-1; j>=0; j--) {
                if(nums[j+1] > nums[j])
                    len++;
                else
                    break;
            }
            maxLen = max(maxLen, len);
        }

        for(int i=1; i<nums.size(); i++) {
            int len = 1;
            for(int j=i-1; j>=0; j--) {
                if(nums[j+1] < nums[j])
                    len++;
                else
                    break;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};