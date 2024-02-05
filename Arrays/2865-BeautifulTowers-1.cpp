/*
    You are given a 0-indexed array maxHeights of n integers.
    You are tasked with building n towers in the coordinate line. The ith tower is built at coordinate i and has a height of heights[i].
    A configuration of towers is beautiful if the following conditions hold:
        1 <= heights[i] <= maxHeights[i]
    Array heights is a mountain if there exists an index i such that:
        For all 0 < j <= i, heights[j - 1] <= heights[j]
        For all i <= k < n - 1, heights[k + 1] <= heights[k]
    Return the maximum possible sum of heights of a beautiful configuration of towers.

    Example 1:
    Input: maxHeights = [5,3,4,1,1]
    Output: 13
    Explanation: One beautiful configuration with a maximum sum is heights = [5,3,3,1,1]. This configuration is beautiful since:
    - 1 <= heights[i] <= maxHeights[i]  
    - heights is a mountain of peak i = 0.
    It can be shown that there exists no other beautiful configuration with a sum of heights greater than 13.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateAns(int peakIdx, vector<int> &maxHeights) {
        vector<int> modified = maxHeights;
        long long ans = modified[peakIdx];

        for (int i = peakIdx - 1; i >= 0; i--) {
            modified[i] = min(modified[i], modified[i + 1]);
            ans += modified[i];
        }

        for (int i = peakIdx + 1; i < modified.size(); i++) {
            modified[i] = min(modified[i], modified[i - 1]);
            ans += modified[i];
        }

        return ans;
    }

    long long maximumSumOfHeights(vector<int> &maxHeights) {
        long long ans = 0;

        for (int i = 0; i < maxHeights.size(); i++)
            ans = max(ans, calculateAns(i, maxHeights));

        return ans;
    }
};