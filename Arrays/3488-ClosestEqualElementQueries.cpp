/*
    You are given a circular array nums and an array queries. For each query i, you have to find the following: The minimum distance between the element at index queries[i] and 
    any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1. Return an array answer of the 
    same size as queries, where answer[i] represents the result for query i.

    Example 1:
    Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]
    Output: [2,-1,3]
    Explanation:
    Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
    Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
    Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 
    5 -> 6 -> 0 -> 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans(queries.size());
        int n = nums.size();

        for(int i=0; i<nums.size(); i++) 
            mp[nums[i]].push_back(i);

        for(auto &i : mp) {
            vector<int> j = i.second;
            sort(j.begin(), j.end());
        }

        for(int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int num = nums[idx];

            auto &vec = mp[num];

            if(vec.size() == 1) {
                ans[i] = -1;
                continue;
            }

            int pos = lower_bound(vec.begin(), vec.end(), idx) - vec.begin();
            int res = INT_MAX;

            if(pos > 0) {
                int d = idx - vec[pos - 1];
                res = min(res, d);
            } else {
                int d = n - (vec.back() - idx);
                res = min(res, d);
            }

            if(pos < vec.size() - 1) {
                int d = vec[pos + 1] - idx;
                res = min(res, d);
            } else {
                int d = n - (idx - vec[0]);
                res = min(res, d);
            }

            ans[i] = res;
        }

        return ans;
    }
};