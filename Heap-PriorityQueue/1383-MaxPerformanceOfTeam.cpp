/*
    You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers 
    numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
    Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
    The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.
    Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

    Example 1:
    Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
    Output: 60
    Explanation: 
    We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 
    (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        vector<pair<int, int>> engineers;

        for (int i = 0; i < n; ++i) {
            engineers.push_back({efficiency[i], speed[i]});
        }

        sort(engineers.begin(), engineers.end());
        reverse(engineers.begin(), engineers.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        unsigned long long totalSpeed = 0;
        unsigned long long maxPerformance = 0;

        for (const auto& eng : engineers) {
            if (minHeap.size() == k) {
                totalSpeed -= minHeap.top();
                minHeap.pop();
            }

            minHeap.push(eng.second);
            totalSpeed += eng.second;

            maxPerformance = max(maxPerformance, totalSpeed * eng.first);
        }

        return maxPerformance % mod;
    }
};