/*
    You are given an integer array nums and two integers k and mul. Select exactly k elements from nums. Process these elements one by one in any order you choose.
    For each selected element, independently choose one of the following: Add the element's value to the total sum, or Multiply the element by the current value of mul and add 
    the result to the total sum. After processing each selected element, mul decreases by 1, regardless of which option was chosen. The current value of mul may become 0 or 
    negative. Return an integer denoting the maximum possible total sum.

    Example 1:
    Input: nums = [6,1,2,9], k = 3, mul = 2
    Output: 26
    Explanation: One optimal way: One optimal selection is nums[3] = 9, nums[0] = 6, and nums[2] = 2.
    Process nums[3] = 9 first: choose multiplication, so it contributes 9 * 2 = 18. Now, mul becomes 1.
    Process nums[0] = 6 next: choose multiplication, so it contributes 6 * 1 = 6. Now, mul becomes 0.
    Process nums[2] = 2 last: choose addition, so it contributes 2.
    The total sum is 18 + 6 + 2 = 26.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        int idx = 0;

        while(k) {
            long long op1 = nums[idx];
            long long op2 = 1LL * nums[idx] * mul;
            ans += max(op1, op2);

            idx++;
            k--;
            mul--;
        }

        return ans;
    }
};