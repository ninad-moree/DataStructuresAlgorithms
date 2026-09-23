/*
    You are given an integer array nums and an integer x. In one operation, you can either 
    remove the leftmost or the rightmost element from the array nums and subtract its value from x.
     Note that this modifies the array for future operations.
    Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, 
    return -1.

    Example 1:
    Input: nums = [1,1,4,2,3], x = 5
    Output: 2
    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

        for(auto i : nums)
            totalSum += i;

        int target = totalSum - x;

        if(target < 0)
            return -1;
        
        if(target == 0)
            return n;

        int left = 0;
        int ans = 1e9;
        int sum = 0;

        for(int right=0; right<n; right++) {
            sum += nums[right];

            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) 
                ans = min(ans, n - (right - left + 1));
        }

        return ans >= 1e9 ? -1 : ans;
    }
};