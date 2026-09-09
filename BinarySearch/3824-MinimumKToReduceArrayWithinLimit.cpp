/*
    You are given a positive integer array nums. For a positive integer k, define nonPositive(nums, k) as the minimum number of operations needed to make every element of nums 
    non-positive. In one operation, you can choose an index i and reduce nums[i] by k. Return an integer denoting the minimum value of k such that nonPositive(nums, k) <= k2.

    Example 1:
    Input: nums = [3,7,5]
    Output: 3
    Explanation: When k = 3, nonPositive(nums, k) = 6 <= k2. Reduce nums[0] = 3 one time. nums[0] becomes 3 - 3 = 0. Reduce nums[1] = 7 three times. 
    nums[1] becomes 7 - 3 - 3 - 3 = -2. Reduce nums[2] = 5 two times. nums[2] becomes 5 - 3 - 3 = -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool nonPositive(vector<int>& nums, long long k) {
        long long ans = 0;

        for (int x : nums) 
            ans += (x + k - 1) / k;

        return ans <= k * k;
    }

    int minimumK(vector<int>& nums) {
        long long low = 1;
        long long high = 1e9;

        while(low < high) {
            long long mid = low + (high - low) / 2;

            if(nonPositive(nums, mid))
                high = mid;
            else
                low = mid+1;
        }

        return (int)low;
    }
};