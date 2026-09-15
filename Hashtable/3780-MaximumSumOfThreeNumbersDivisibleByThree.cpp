/*
    You are given an integer array nums. Your task is to choose exactly three integers from nums such that their sum is divisible by three. Return the maximum possible sum of 
    such a triplet. If no such triplet exists, return 0.

    Example 1:
    Input: nums = [4,2,3,1]
    Output: 9
    Explanation: The valid triplets whose sum is divisible by 3 are: (4, 2, 3) with a sum of 4 + 2 + 3 = 9. (2, 3, 1) with a sum of 2 + 3 + 1 = 6. Thus, the answer is 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        unordered_map<int, vector<int>> mp;
        for(auto i : nums) 
            mp[i % 3].push_back(i);

        int ans = 0;

        // 0-0-0
        if(mp[0].size() >= 3) {
            int n1 = mp[0][0];
            int n2 = mp[0][1];
            int n3 = mp[0][2];

            ans = max(ans, n1 + n2 + n3);
        }

        // 1-1-1
        if(mp[1].size() >= 3) {
            int n1 = mp[1][0];
            int n2 = mp[1][1];
            int n3 = mp[1][2];

            ans = max(ans, n1 + n2 + n3);
        }

        // 2-2-2
        if(mp[2].size() >= 3) {
            int n1 = mp[2][0];
            int n2 = mp[2][1];
            int n3 = mp[2][2];

            ans = max(ans, n1 + n2 + n3);
        }

        // 0-1-2
        if(mp[0].size() > 0 && mp[1].size() > 0 && mp[2].size() > 0) {
            int n1 = mp[0][0];
            int n2 = mp[1][0];
            int n3 = mp[2][0];

            ans = max(ans, n1 + n2 + n3);
        }

        return ans;
    }
};