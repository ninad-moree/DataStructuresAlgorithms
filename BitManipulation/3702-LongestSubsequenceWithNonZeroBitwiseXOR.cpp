/*
    You are given an integer array nums. Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

    Example 1:
    Input: nums = [1,2,3]
    Output: 2
    Explanation: One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZero = true;

        for (int x : nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }

        if (totalXor > 0) {
            return n;
        }

        return allZero ? 0 : n - 1;
    }
};