/*
    You are given an array of integers nums of length n.
    The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 
    while the cost of [3,4,1] is 3.
    You need to divide nums into 3 disjoint contiguous subarrays.
    Return the minimum possible sum of the cost of these subarrays.

    Example 1:
    Input: nums = [1,2,3,12]
    Output: 6
    Explanation: The best possible way to form 3 subarrays is: [1], [2], and [3,12] at a total cost of 1 + 2 + 3 = 6.
    The other possible ways to form 3 subarrays are:
    - [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
    - [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        sort(nums.begin()+1,nums.end());
        ans = ans + nums[1] + nums[2];
        
        return ans;
    }
};