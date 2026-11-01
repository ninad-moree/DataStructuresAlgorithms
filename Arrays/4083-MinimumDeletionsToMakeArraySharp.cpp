/*
    You are given an integer array nums. You may delete any number of elements from nums. The remaining elements keep their original order. The resulting array a is sharp if the
    bitwise XOR of every pair of adjacent elements is non-zero. That is, a[i] XOR a[i + 1] != 0 for every index i such that 0 <= i < a.length - 1. An array with at most one 
    element is sharp. Return the minimum number of deletions needed to make nums sharp. Bitwise XOR compares the corresponding bits of two integers. A bit in the result is 1 if
    the corresponding bits differ, and 0 otherwise.

    Example 1:
    Input: nums = [1,1,2,2,2,3]
    Output: 3
    Explanation: The pairs at indices (0, 1), (2, 3), and (3, 4) each have an XOR of 0. Deleting one 1 and two 2s leaves [1, 2, 3], where 1 XOR 2 == 3 and 2 XOR 3 == 1 are both
    non-zero. Therefore, the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int prev = nums[0];
        int cnt = 0;

        while(i < n) {
            while(i < n && nums[i] == prev) {
                i++;
                cnt++;
            }

            prev = nums[i];
            i++;
        }

        return cnt;
    }
};