/*
    You are given a 0-indexed array nums of integers.
    A triplet of indices (i, j, k) is a mountain if:
    i < j < k
    nums[i] < nums[j] and nums[k] < nums[j]
    Return the minimum possible sum of a mountain triplet of nums. If no such triplet exists, return -1.

    Example 1:
    Input: nums = [8,6,1,5,3]
    Output: 9
    Explanation: 
    nums[2] < nums[3] and nums[4] < nums[3]
    sum of this triplet is nums[2] + nums[3] + nums[4] = 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        int curr = INT_MAX;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    if(nums[i]<nums[j] && nums[k]<nums[j]) {
                        curr = nums[i] + nums[j] + nums[k];
                        ans = min(curr, ans);
                    }
                }
            }
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};