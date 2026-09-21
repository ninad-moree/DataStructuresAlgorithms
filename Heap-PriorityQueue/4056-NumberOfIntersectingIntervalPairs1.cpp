/*
    You are given a 2D integer array intervals of n elements, where intervals[i] = [starti, endi] represents the closed interval from starti to endi. Return the number of pairs 
    of indices (i, j) such that 0 <= i < j < n and intervals[i] and intervals[j] intersect. Two intervals intersect if they have at least one point in common, including when 
    they only share an endpoint.

    Example 1:
    Input: intervals = [[1,2],[2,3],[3,4]]
    Output: 2
    Explanation: There are 2 intersecting interval pairs: Intervals [1, 2] and [2, 3] intersect at the point 2. Intervals [2, 3] and [3, 4] intersect at the point 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(intervals[0][1]);

        int ans = 0;

        for(int i=1; i<intervals.size(); i++) {
            while(!pq.empty() && pq.top() < intervals[i][0])
                pq.pop();

            ans += pq.size();
            pq.push(intervals[i][1]);
        }

        return ans;
    }
};