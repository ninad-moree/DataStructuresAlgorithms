/*
    Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
    You can return the answer in any order. You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Example 1:
    Input: nums = [1,2,1,3,2,5]
    Output: [3,5]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;

        for(auto i : nums)
            XOR = XOR ^ i;

        int rightMostSetBit = (XOR & XOR-1) ^ XOR;

        int b1 = 0;
        int b2 = 0;

        for(auto i : nums) {
            if(i & rightMostSetBit)
                b1 = b1 ^ i;
            else
                b2 = b2 ^ i;
        }

        return {b1, b2};
    }
};