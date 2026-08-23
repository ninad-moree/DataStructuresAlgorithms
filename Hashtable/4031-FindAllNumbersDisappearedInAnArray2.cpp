/*
    You are given an integer array nums and two integers lower and upper. A missing integer is an integer in the inclusive range [lower, upper] that does not appear in nums.
    Return a 2D integer array where each element is of the form [start, end], representing a contiguous range of missing integers. Return the ranges in increasing order. If 
    there are no missing integers, return an empty array. Note: Consecutive missing integers should be grouped into a single range.

    Example 1:
    Input: nums = [3,9,7], lower = 1, upper = 12
    Output: [[1,2],[4,6],[8,8],[10,12]]
    Explanation: The missing integers are [1, 2, 4, 5, 6, 8, 10, 11, 12]. Grouping the missing integers into the minimum number of contiguous ranges, we get [1, 2], [4, 6], 
    [8, 8], and [10, 12]. Therefore, the answer is [[1, 2], [4, 6], [8, 8], [10, 12]].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;

        vector<int> arr;
        for(int i=lower; i<=upper; i++) {
            if(mp.find(i) == mp.end())
                arr.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> res;

        if(arr.size() == 0)
            return ans;

        int prev = arr[0];
        res.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == prev + 1)
                prev = arr[i];
            else {
                res.push_back(prev);
                ans.push_back(res);
                res.clear();

                // new range
                res.push_back(arr[i]);
                prev = arr[i];
            }
        }

        res.push_back(prev);
        ans.push_back(res);

        return ans;
    }
};