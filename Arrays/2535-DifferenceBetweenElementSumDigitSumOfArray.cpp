/*
    You are given a positive integer array nums. The element sum is the sum of all the elements in nums.
    The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
    Return the absolute difference between the element sum and digit sum of nums.

    Example 1:
    Input: nums = [1,15,6,3]
    Output: 9
    Explanation: 
    The element sum of nums is 1 + 15 + 6 + 3 = 25.
    The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
    The absolute difference between the element sum and digit sum is |25 - 16| = 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0;
        int digSum = 0;

        for(auto i : nums) 
            eleSum += i;
        
        for(auto i : nums) {
            string s = to_string(i);
            for(int j=0; j<s.size(); j++) {
                string str = "";
                str += s[j];
                int dig = stoi(str);
                digSum += dig;
            }
        }

        return abs(eleSum - digSum);
    }
};