/*
    You are given an array nums of non-negative integers and an integer k.
    An array is called special if the bitwise OR of all of its elements is at least k.
    Return the length of the shortest special non-empty 
    subarray of nums, or return -1 if no special subarray exists.

    Example 1:
    Input: nums = [1,2,3], k = 2
    Output: 1
    Explanation:
    The subarray [3] has OR value of 3. Hence, we return 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int bitwiseOR = 0;
            for (int j = i; j < n; ++j) {
                bitwiseOR |= nums[j];
                if (bitwiseOR >= k) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};