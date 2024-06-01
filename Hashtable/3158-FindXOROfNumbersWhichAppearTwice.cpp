/*
    You are given an array nums, where each number in the array appears either once or twice.
    Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

    Example 1:
    Input: nums = [1,2,1,3]
    Output: 1
    Explanation:
    The only number that appears twice in nums is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i : nums) 
            mp[i]++;
        
        int ans = 0;

        for(auto i : mp) {
            if(i.second == 2)
                ans = ans^i.first;
        }

        return ans;
    }
};