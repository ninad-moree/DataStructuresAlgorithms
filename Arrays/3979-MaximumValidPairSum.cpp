/*
    You are given an integer array nums of length n and an integer k. A pair of indices (i, j) is called valid if: 0 <= i < j < n and j - i >= k
    Return the maximum value of nums[i] + nums[j] among all valid pairs.

    Example 1:
    Input: nums = [1,3,5,2,8], k = 2
    Output: 13
    Explanation: The valid pairs are:
    (0, 2): nums[0] + nums[2] = 6, (0, 3): nums[0] + nums[3] = 3, (0, 4): nums[0] + nums[4] = 9, (1, 3): nums[1] + nums[3] = 5, (1, 4): nums[1] + nums[4] = 11
    (2, 4): nums[2] + nums[4] = 13
    Thus, the answer is 13.​​​​​​​
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int maxi = nums[0];

        for(int j=k; j<n; j++) {
            maxi = max(maxi, nums[j-k]);
            ans = max(ans, maxi + nums[j]);
        }

        return ans;
    }
};