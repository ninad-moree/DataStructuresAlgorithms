/*
    Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating 
    them in the same order they appear in nums. To separate the digits of an integer is to get all the digits it has in the same order.
    For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

    Example 1:
    Input: nums = [13,25,83,77]
    Output: [1,3,2,5,8,3,7,7]
    Explanation: 
    answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            string s = to_string(n);

            for(int j=0; j<s.size(); j++) {
                int m = s[j] - '0';
                ans.push_back(m);
            }
        }

        return ans;
    }
};