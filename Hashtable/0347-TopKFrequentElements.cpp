/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) 
            mp[nums[i]]++;
         
        vector<pair<int, int>> freqPairs;
        for (auto it : mp) 
            freqPairs.push_back({it.first, it.second});
        
        sort(freqPairs.begin(), freqPairs.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; i++) 
            ans.push_back(freqPairs[i].first);
        
        return ans;
    }
};