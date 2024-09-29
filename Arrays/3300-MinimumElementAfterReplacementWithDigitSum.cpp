/*
    You are given an integer array nums. You replace each element in nums with the sum of its digits. Return the minimum element in nums after all 
    replacements.

    Example 1:
    Input: nums = [10,12,13,14]
    Output: 1
    Explanation: nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDigit(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n%10;
            n = n/10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] = sumDigit(nums[i]);
        }

        sort(nums.begin(), nums.end());

        return nums[0];
    }
};