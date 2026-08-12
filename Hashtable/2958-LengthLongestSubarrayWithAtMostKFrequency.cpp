/*
    You are given an integer array nums and an integer k.
    The frequency of an element x is the number of times it occurs in an array.
    An array is called good if the frequency of each element in this array is less than or equal to k.
    Return the length of the longest good subarray of nums.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,2,3,1,2,3,1,2], k = 2
    Output: 6
    Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this 
    subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
    It can be shown that there are no good subarrays with length more than 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxLen = 0;

        unordered_map<int, int> mp;

        while(j < n) {
            mp[nums[j]]++;

            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);

            j++;
        }

        return maxLen;
    }
};