/*
    Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
    and each integer appears once or twice, return an array of all the integers that appears twice.
    You must write an algorithm that runs in O(n) time and uses only constant extra space.

    Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [2,3]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int num : nums) 
            mp[num]++;
        
        for (const auto& pair : mp) {
            if (pair.second > 1) 
                ans.push_back(pair.first);
        }
        return ans;
    }
};