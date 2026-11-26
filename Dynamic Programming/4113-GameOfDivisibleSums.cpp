/*
    Alice and Bob are playing a game with an integer array nums. Alice goes first. On each turn, the current player takes and removes either the leftmost element or, if at 
    least two elements remain, the two leftmost elements. The sum of the elements taken in that turn determines who plays next: If the sum is divisible by 3, the other player 
    plays next. Otherwise, the same player plays again.The score of a player is the sum of the values of all elements that player takes. Both players play optimally, with each 
    player trying to maximize their own score. The game ends when all elements have been taken. Return Alice's score minus Bob's score.

    Example 1:
    Input: nums = [3,6,4]
    Output: 5
    Explanation: One sequence of optimal turns is as follows: Alice takes the two leftmost elements. Their sum is 3 + 6 = 9, which is divisible by 3, so Bob plays next. 
    Alice's score is now 9, and the remaining array is [4]. Bob takes the only remaining element. His score is 4, and the game ends. Alice's score minus Bob's score is 9 - 4 = 5
    so the answer is 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int idx, vector<int>& nums, vector<long long>& dp, vector<int>& vis) {
        if(idx >= nums.size())
            return 0;

        if(vis[idx] == 1)
            return dp[idx];

        // take 1
        long long s1 = nums[idx];
        long long take1 = (s1 % 3 == 0) ? s1 - solve(idx+1, nums, dp, vis) : s1 + solve(idx+1, nums, dp, vis);

        // take 2
        long long take2 = LLONG_MIN;
        if(idx + 1 < nums.size()) {
            long long s2 = (long long)nums[idx] + nums[idx + 1];
            take2 = (s2 % 3 == 0) ? s2 - solve(idx+2, nums, dp, vis) : s2 + solve(idx+2, nums, dp, vis);
        }

        vis[idx] = 1;
        return dp[idx] = max(take1, take2);
    }

    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n);
        vector<int> vis(n);

        return solve(0, nums, dp, vis);
    }
};