/*
    Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) 
    where 0 <= i < j < n and nums[i] + nums[j] < target.

    Example 1:
    Input: nums = [-1,1,2,3,1], target = 2
    Output: 3
    Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
    - (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
    - (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
    - (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
    Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size()-1;
        int cnt = 0;

        while(i<j) {
            if(nums[i] + nums[j] < target) {
                cnt += (j-i);
                i++;
            }
            else 
                j--;
        }

        return cnt;
    }
};