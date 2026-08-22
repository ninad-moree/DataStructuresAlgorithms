/*
    You are given two 2D integer arrays series1 and series2. Each element in both series is of the form [timestamp, value], where: timestamp is an integer representing the time.
    value is an integer representing the value at that timestamp. Each array is sorted in strictly increasing order of timestamp. For any timestamp not present in a series, its
    value is taken from the next available timestamp in the same series if one exists. Otherwise, its value is considered 0. The aggregated series is formed by summing the 
    corresponding values from both series at every timestamp that appears in either series. Return the aggregated series as a 2D integer array of [timestamp, summedValue] 
    pairs, sorted in strictly increasing order of timestamp.

    Example 1:
    Input: series1 = [[1,3],[4,1]], series2 = [[2,2],[5,2]]
    Output: [[1,5],[2,3],[4,3],[5,2]]
    Explanation:
    Timestamp	series1	series2	summedValue
    1	3	2	5
    2	1	2	3
    4	1	2	3
    5	0	2	2
    Thus, the aggregated series is [[1, 5], [2, 3], [4, 3], [5, 2]].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n1 = series1.size();
        int n2 = series2.size();

        int i = 0;
        int j = 0;

        while(i < n1 || j < n2) {
            int t;

            if(i == n1)
                t = series2[j][0];
            else if(j == n2)
                t = series1[i][0];
            else
                t =  min(series1[i][0], series2[j][0]);

            int v1 = 0;
            if(i < n1)
                v1 = series1[i][1];

            int v2 = 0;
            if(j < n2)
                v2 = series2[j][1];

            ans.push_back({t, v1 + v2});

            if(i < n1 && series1[i][0] == t)
                i++;
            if(j < n2 && series2[j][0] == t)
                j++;
        }

        return ans;
    }
};