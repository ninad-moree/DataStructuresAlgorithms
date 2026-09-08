/*
    You are given an integer array nums. Return an integer denoting the first element (scanning from left to right) in nums whose frequency is unique. That is, no other integer
    appears the same number of times in nums. If there is no such element, return -1.

    Example 1:
    Input: nums = [20,10,30,30]
    Output: 30
    Explanation: 20 appears once. 10 appears once. 30 appears twice. The frequency of 30 is unique because no other integer appears exactly twice.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i : nums)
            mp[i]++;

        int maxFreq = INT_MIN;
        for(auto i : mp)
            maxFreq = max(maxFreq, i.second);

        vector<int> freq(maxFreq+1);

        for(auto i : mp) {
            int fq = i.second;
            freq[fq]++;
        }

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            int f = mp[n];

            if(freq[f] == 1)
                return n;
        }

        return -1;
    }
};