/*
    You are given an integer array nums. An integer x is special if all occurrences of x in nums appear in a single contiguous block. Return the number of distinct special 
    integers in nums.

    Example 1:
    Input: nums = [1,2,2,1]
    Output: 1
    Explanation: 1 appears at indices 0 and 3, forming two separate blocks, so it is not special. 2 appears in a single contiguous block at indices [1, 2], so it is special.
    Therefore, there is one special integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = 0;

        for(int i=0; i<nums.size(); i++) 
            mp[nums[i]].push_back(i);
        
        for(auto i : mp) {
            int num = i.first;
            vector<int> idx = i.second;
            bool res = true;

            for(int j=1; j<idx.size(); j++) {
                if(idx[j-1] + 1 != idx[j]) {
                    res = false;
                    break;
                }
            }

            if(res)
                ans++;
        }

        return ans;
    }
};