/*
    You are given an array nums of distinct positive integers. You need to sort the array in increasing order based on the sum of the digits of each number. If two numbers have
    the same digit sum, the smaller number appears first in the sorted order. Return the minimum number of swaps required to rearrange nums into this sorted order.
    A swap is defined as exchanging the values at two distinct positions in the array.

    Example 1:
    Input: nums = [37,100]
    Output: 1
    Explanation: Compute the digit sum for each integer: [3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1] Sort the integers based on digit sum: [100, 37]. Swap 37 with 100 to obtain the 
    sorted order. Thus, the minimum number of swaps required to rearrange nums is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int ans = 0;
        string num = to_string(n);

        for(int i=0; i<num.size(); i++) {
            ans += (num[i] - '0');
        }

        return ans;
    }

    int minSwaps(vector<int>& nums) {
        map<int, vector<int>> mp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int ds = digitSum(nums[i]);
            mp[ds].push_back(nums[i]);
        }

        for(auto i : mp) {
            vector<int> vec = i.second;
            sort(vec.begin(), vec.end());

            for(auto j : vec)
                ans.push_back(j);
        }

        unordered_map<int, int> pos;

        for(int i = 0; i < ans.size(); i++) 
            pos[ans[i]] = i;

        int swaps = 0;
        vector<bool> vis(nums.size(), false);

        for(int i = 0; i < nums.size(); i++) {
            if(vis[i] || pos[nums[i]] == i)
                continue;

            int j = i;
            int cycle = 0;

            while(!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};