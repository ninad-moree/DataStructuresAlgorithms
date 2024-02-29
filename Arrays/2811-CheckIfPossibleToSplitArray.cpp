/*
    You are given an array nums of length n and an integer m. You need to determine if it is possible to split the array into n 
    non-empty arrays by performing a series of steps.
    In each step, you can select an existing array (which may be the result of previous steps) with a length of at least two and 
    split it into two subarrays, if, for each resulting subarray, at least one of the following holds:
    The length of the subarray is one, or
    The sum of elements of the subarray is greater than or equal to m.
    Return true if you can split the given array into n arrays, otherwise return false.
    Note: A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [2, 2, 1], m = 4
    Output: true
    Explanation: We can split the array into [2, 2] and [1] in the first step. Then, in the second step, we can split [2, 2] into 
    [2] and [2]. As a result, the answer is true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] + nums[i + 1] >= m) 
                return true;
        }
        return false;
    }
};