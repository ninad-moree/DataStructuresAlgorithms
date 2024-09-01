/*
    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    0 <= a, b, c, d < n a, b, c, and d are distinct. nums[a] + nums[b] + nums[c] + nums[d] == target You may return the answer in any order.

    Example 1:
    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        set<vector<int>> st;
        
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                int k = j+1;
                int l = nums.size()-1;

                while(k < l) {
                    long long int sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if ( sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }

        for(auto i : st)
            ans.push_back(i);

        return ans;
    }
};