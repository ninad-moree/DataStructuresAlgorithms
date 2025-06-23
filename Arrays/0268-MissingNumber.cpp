/*
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the 
    array.

    Example 1:
    Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it 
    does not appear in nums.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;

        int actualSum;
        int n = nums.size();
        actualSum  = n*(n+1)/2;

        return abs(actualSum - sum);
    }

    int missingNumber2(vector<int>& nums) {
        int XOR1 = 0;
        int XOR2 = 0;

        for(int i=0; i<nums.size(); i++) {
            XOR1 = XOR1 ^ i;
            XOR2 = XOR2 ^ nums[i];
        }

        XOR1 = XOR1 ^ (nums.size());

        return XOR1 ^ XOR2;
    }
};