/*
    You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
    Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
    Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
    The gcd of two integers is the greatest common divisor of the two integers.

    Example 1:
    Input: nums = [2,6,3,4]
    Output: 4
    Explanation: We can do the following operations:
    - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
    - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
    - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
    - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int noOne = 0;
        int mini = INT_MAX;

        for(auto i : nums) {
            if(i!=1)
                noOne++;
        }

        for(int i=0; i<nums.size(); i++) {
            int gcd = nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                gcd = __gcd(gcd, nums[j]);
                if(gcd == 1)
                    mini = min(mini, j-i);
            }
        }

        if(mini == INT_MAX)
            return -1;
        
        return noOne + mini - 1;
    }
};