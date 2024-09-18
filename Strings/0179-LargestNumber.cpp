/*
    Given a list of non-negative integers nums, arrange them such that they form the largest number and return it. Since the result may be very large, so 
    you need to return a string instead of an integer.

    Example 1:
    Input: nums = [10,2]
    Output: "210"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";

        sort(nums.begin(), nums.end(), [](auto a, auto b) {
            string a1 = to_string(a);
            string b1 = to_string(b);

            return ((a1 + b1) > (b1 + a1));
        });

        if(nums[0] == 0)
            return "0";

        for(auto i : nums) 
            ans += to_string(i);

        return ans;
    }
};