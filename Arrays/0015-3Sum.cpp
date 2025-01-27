/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + 
    nums[k] == 0. Notice that the solution set must not contain duplicate triplets.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> sums;

        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < nums.size()) {
            int j = i+1;
            int k = nums.size() - 1;

            while(j < k) {
                int n1 = nums[i];
                int n2 = nums[j];
                int n3 = nums[k];

                if(n1 + n2 + n3 == 0) {
                    sums.insert({n1, n2, n3});
                    j++;
                    k--;
                } else if (n1 + n2 + n3 < 0) 
                    j++;
                else
                    k--;
            }

            i++;
        }

        for(auto i : sums)
            ans.push_back(i);

        return ans;
    }
};