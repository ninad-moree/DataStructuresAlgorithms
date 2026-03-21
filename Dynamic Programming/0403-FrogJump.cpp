/*
    A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must 
    not jump into the water. Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. 
    Initially, the frog is on the first stone and assumes the first jump must be 1 unit. If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 
    units. The frog can only jump in the forward direction.

    Example 1:
    Input: stones = [0,1,3,5,6,8,12,17]
    Output: true
    Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th 
    stone, 4 units to the 7th stone, and 5 units to the 8th stone.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx, int jump, vector<int>& stones, unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        if(idx == stones.size()-1)
            return true;

        if(dp[idx][jump] != -1)
            return dp[idx][jump];

        bool ans = false;

        for(int nextJump=jump-1; nextJump<=jump+1; nextJump++) {
            if(nextJump <= 0)
                continue;

            int nextPos = stones[idx] + nextJump;

            if(mp.find(nextPos) != mp.end())
                ans = ans | solve(mp[nextPos], nextJump, stones, mp, dp);
        }

        return dp[idx][jump] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        for(int i=0; i<stones.size(); i++)
            mp[stones[i]] = i;

        return solve(0, 0, stones, mp, dp);
    }
};