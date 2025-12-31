/*
    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
    Only numbers 1 through 9 are used. Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

    Example 1:
    Input: k = 3, n = 7
    Output: [[1,2,4]]
    Explanation: 1 + 2 + 4 = 7
    There are no other valid combinations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, int k, int n, vector<int> arr, vector<vector<int>>& ans) {
        if(arr.size() == k) {
            if(n == 0)
                ans.push_back(arr);
            return;
        }

        for(int i=idx; i<=9; i++) {
            if(i > n)
                break;
            
            arr.push_back(i);
            solve(i+1, k, n-i, arr, ans);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;

        solve(1, k, n, arr, ans);

        return ans;
    }
};