/*
    Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
    Return the number of nice sub-arrays.

    Example 1:
    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;

        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;

        while(r < nums.size()) {
            sum += (nums[r] % 2);

            while(sum > goal) {
                sum -= (nums[l] % 2);
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};