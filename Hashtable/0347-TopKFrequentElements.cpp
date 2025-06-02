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
    struct Compare {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        unordered_map<int, int> mp;

        for(auto i : nums) 
            mp[i]++;

        for(auto i : mp) {
            int n = i.first;
            int f = i.second;

            pq.push({n, f});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();

            ans.push_back(f.first);
        }

        return ans;
    }
};