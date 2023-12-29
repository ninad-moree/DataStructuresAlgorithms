/*
    You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the 
    jobs j where 0 <= j < i).
    You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of 
    the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
    You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
    Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

    Example 1:
    Input: jobDifficulty = [6,5,4,3,2,1], d = 2
    Output: 7
    Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
    Second day you can finish the last job, total difficulty = 1.
    The difficulty of the schedule = 6 + 1 = 7 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(std::vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) 
            return -1;

        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX / 2));

        dp[0][0] = 0;

        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= n; ++j) {
                int maxDifficulty = 0;
                for (int k = j - 1; k >= i - 1; --k) {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxDifficulty);
                }
            }
        }

        return dp[d][n] != INT_MAX / 2 ? dp[d][n] : -1;
    }
};