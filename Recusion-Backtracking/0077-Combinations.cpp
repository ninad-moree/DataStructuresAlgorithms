/*
    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n]. You may return the answer in any order.

    Example 1:
    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    Explanation: There are 4 choose 2 = 6 total combinations. Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& arr, int k, int idx, vector<int>& res, vector<vector<int>>& ans) {
        if(idx >= arr.size()) {
            if(res.size() == k) 
                ans.push_back(res);
            return;
        }

        if(res.size() == k) {
            ans.push_back(res);
            return;
        }

        // take
        res.push_back(arr[idx]);
        solve(arr, k, idx+1, res, ans);
        res.pop_back();

        solve(arr, k, idx+1, res, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        vector<vector<int>> ans;
        vector<int> arr;

        for(int i=1; i<=n; i++)
            arr.push_back(i);

        solve(arr, k, 0, res, ans);

        return ans;
    }
};