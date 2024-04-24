/*
    We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
    You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two 
    jobs in the subset with overlapping time range.
    If you choose a job that ends at time X you will be able to start another job that starts at time X.

    Example 1:
    Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
    Output: 120
    Explanation: The subset chosen is the first and fourth job. 
    Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();

        for (int i = 0; i < n; ++i) 
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<vector<int>> dp = {{0, 0}}; // [time, profit]

        for (auto& job : jobs) {
            int s = job[0]; 
            int e = job[1];
            int p = job[2];

            int idx = lower_bound(dp.begin(), dp.end(), vector<int>{s + 1}) - dp.begin() - 1;

            if (dp[idx][1] + p > dp.back()[1]) 
                dp.push_back({e, dp[idx][1] + p});
        }

        return dp.back()[1];
    }
};