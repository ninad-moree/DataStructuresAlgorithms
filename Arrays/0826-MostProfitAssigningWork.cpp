/*
    You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where: difficulty[i] and profit[i] are the 
    difficulty and the profit of the ith job, and worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with 
    difficulty at most worker[j]). Every worker can be assigned at most one job, but one job can be completed multiple times.
    For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, 
    their profit is $0. Return the maximum profit we can achieve after assigning the workers to the jobs.

    Example 1:
    Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
    Output: 100
    Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;

        vector<vector<int>> arr;
        for(int i=0; i<profit.size(); i++) 
            arr.push_back({profit[i], difficulty[i]});

        sort(arr.begin(), arr.end());
        sort(worker.begin(), worker.end());

        int i = arr.size()-1;
        int j = worker.size()-1;

        while(j >= 0 && i>=0) {
            if(arr[i][1] > worker[j])
                i--;
            else {
                ans += arr[i][0];
                j--;
            }
        }

        return ans;
    }
};