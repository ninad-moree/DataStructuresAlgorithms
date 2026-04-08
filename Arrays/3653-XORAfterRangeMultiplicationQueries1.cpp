/*
    You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi]. For each query, you must apply the following 
    operations in order: Set idx = li. While idx <= ri: Update: nums[idx] = (nums[idx] * vi) % (109 + 7) Set idx += ki.
    Return the bitwise XOR of all elements in nums after processing all queries.

    Example 1:
    Input: nums = [1,1,1], queries = [[0,2,1,4]]
    Output: 4
    Explanation: A single query [0, 2, 1, 4] multiplies every element from index 0 through index 2 by 4. The array changes from [1, 1, 1] to [4, 4, 4].
    The XOR of all elements is 4 ^ 4 ^ 4 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;

        for(auto i : queries) {
            int l = i[0];
            int r = i[1];
            int k = i[2];
            int v = i[3];

            for(int j=l; j<=r; j+=k) 
                nums[j] = (1LL * nums[j] * v) % MOD;
        }

        int ans = 0;
        for(auto i : nums) 
            ans = ans ^ i;
        
        return ans;
    }
};