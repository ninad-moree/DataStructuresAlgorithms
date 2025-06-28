/*
    You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum. Return any 
    such subsequence as an integer array of length k. A subsequence is an array that can be derived from another array by deleting some or no 
    elements without changing the order of the remaining elements.

    Example 1:
    Input: nums = [2,1,3,3], k = 2
    Output: [3,3]
    Explanation:
    The subsequence has the largest sum of 3 + 3 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});

            if(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()) {
            auto n = pq.top();
            ans.push_back(n.second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++)
            ans[i] = nums[ans[i]];

        return ans;
    }
};