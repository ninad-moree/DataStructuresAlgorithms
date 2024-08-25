/*
    You are given an integer array nums, an integer k, and an integer multiplier. You need to perform k operations on nums. In each operation:
    Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
    Replace the selected minimum value x with x * multiplier. Return an integer array denoting the final state of nums after performing all k operations.

    Example 1:
    Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
    Output: [8,4,6,5,6]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size());

        auto cmp = [](auto& a, auto& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        };

        priority_queue< pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for(int i=0; i<nums.size(); i++)
            pq.push({nums[i], i});

        while(k--) {
            auto f = pq.top();
            pq.pop();

            f.first = f.first * multiplier;
            pq.push(f);
        }

        while(!pq.empty()) {
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};