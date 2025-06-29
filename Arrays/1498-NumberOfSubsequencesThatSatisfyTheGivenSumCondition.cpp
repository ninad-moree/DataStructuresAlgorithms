/*
    You are given an array of integers nums and an integer target. Return the number of non-empty subsequences of nums such that the sum of the 
    minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

    Example 1:
    Input: nums = [3,5,6,7], target = 9
    Output: 4
    Explanation: There are 4 subsequences that satisfy the condition.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int mod = 1e9 + 7;

        vector<int> pow2(nums.size() + 1, 1);
        for(int i=1; i<=nums.size(); i++) 
            pow2[i] = (pow2[i-1] * 2 * 1LL) % mod;

        int i = 0;
        int j = nums.size() - 1;
        int ans = 0;

        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                ans = (ans + pow2[j - i]) % mod;
                i++;
            } else
                j--;
        }

        return ans;
    }
};