/*
    You are given an integer array nums with the following properties:
    nums.length == 2 * n.
    nums contains n + 1 unique elements.
    Exactly one element of nums is repeated n times.
    Return the element that is repeated n times.

    Example 1:
    Input: nums = [1,2,3,3]
    Output: 3
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;

        int ans;

        for(auto i : mp) {
            if(i.second == nums.size()/2) {
                ans = i.first;
                break;
            }
        }

        return ans;
    }
};