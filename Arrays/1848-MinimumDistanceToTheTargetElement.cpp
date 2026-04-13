/*
    Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is 
    the absolute value of x. Return abs(i - start). It is guaranteed that target exists in nums.

    Example 1:
    Input: nums = [1,2,3,4,5], target = 5, start = 3
    Output: 1
    Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                int diff = abs(i - start);
                ans = min(ans, diff);
            }
        }

        return ans;
    }
};