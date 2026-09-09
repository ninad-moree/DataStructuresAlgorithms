/*
    You are given an integer array nums. You need to remove exactly one prefix (possibly empty) from nums. Return an integer denoting the minimum length of the removed prefix 
    such that the remaining array is strictly increasing.

    Example 1:
    Input: nums = [1,-1,2,3,3,4,5]
    Output: 4
    Explanation: Removing the prefix = [1, -1, 2, 3] leaves the remaining array [3, 4, 5] which is strictly increasing.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int idx = -1;

        for(int i=nums.size()-1; i>=1; i--) {
            if(nums[i] <= nums[i-1]) {
                idx = i;
                break;
            }
        }

        return idx == -1 ? 0 : idx;
    }
};