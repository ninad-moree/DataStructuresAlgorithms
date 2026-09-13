/*
    You are given an integer n representing a target score. Your score starts at 0, and each day you either earn points or skip. Points are earned during a streak. On the first
    day of a streak you earn 1 point, on the second day 2 points, on the third day 3 points, and so on. Skipping a day earns nothing and resets the streak, so the next time you
    earn points, you start from 1 again. Return the minimum number of days, including any skipped days, needed to reach a score of exactly n.

    Example 1:
    Input: n = 2
    Output: 3
    Explanation:​​​​​​​ Day 1: earn 1 point. Score is 1. Day 2: skip, which resets the streak. Earning here would add 2 points and take the score past n = 2.
    Day 3: the streak has reset, so earning gives 1 point. Score is exactly n = 2 in 3 days.
*/

#include<bits/stdc++.h>
using namespace std;

/* GIVES TLE (998/999 Testcases) */
class Solution {
public:
    int solve(int score, int streak, int n, vector<vector<int>>& dp) {
        if(score == n)
            return 0;

        if(score > n)
            return 1e9;

        if(dp[score][streak] != -1)
            return dp[score][streak];

        int take = 1 + solve(score + streak + 1, streak + 1, n, dp);

        int notTake = 1e9;

        if(streak > 0)
            notTake = 1 + solve(score, 0, n, dp);

        return dp[score][streak] = min(take, notTake);
    }

    int minDays(int n) {
        int maxStreak = sqrt(2 * n) + 2;

        vector<vector<int>> dp(n+1, vector<int>(maxStreak+1, -1));

        return solve(0, 0, n, dp);
    }
};