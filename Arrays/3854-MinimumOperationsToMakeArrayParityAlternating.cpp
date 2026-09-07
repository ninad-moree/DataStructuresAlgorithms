/*
    You are given an integer array nums. An array is called parity alternating if for every index i where 0 <= i < n - 1, nums[i] and nums[i + 1] have different parity (one is 
    even and the other is odd). In one operation, you may choose any index i and either increase nums[i] by 1 or decrease nums[i] by 1. Return an integer array answer of length
    2 where: answer[0] is the minimum number of operations required to make the array parity alternating. answer[1] is the minimum possible value of max(nums) - min(nums) taken
    over all arrays that are parity alternating and can be obtained by performing exactly answer[0] operations. An array of length 1 is considered parity alternating.

    Example 1:
    Input: nums = [-2,-3,1,4]
    Output: [2,6]
    Explanation: Applying the following operations: Increase nums[2] by 1, resulting in nums = [-2, -3, 2, 4]. Decrease nums[3] by 1, resulting in nums = [-2, -3, 2, 3].
    The resulting array is parity alternating, and the value of max(nums) - min(nums) = 3 - (-3) = 6 is the minimum possible among all parity alternating arrays obtainable 
    using exactly 2 operations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &nums , bool even){
        int op = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int num : nums){
            if((num % 2 && even) || (num % 2 == 0 && !even)) {
                op++;
                maxi = max(maxi , num - 1);
                mini = min(mini , num + 1);
            } else {
                maxi = max(num , maxi);
                mini = min(num , mini);
            }

            even = !even;
        }
        return {op , maxi - mini};
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) 
            return {0, 0};

        // All numbers are same
        unordered_set<int> st(nums.begin() , nums.end());
        if(st.size() == 1)
            return {(int)n / 2 , 1};
        
        vector<int> evenOdd = solve(nums, 1);
        vector<int> oddEven = solve(nums, 0);

        if(evenOdd[0] == oddEven[0])
            return evenOdd[1] < oddEven[1] ? evenOdd : oddEven;
        return evenOdd[0] < oddEven[0] ? evenOdd : oddEven;
    }
};
