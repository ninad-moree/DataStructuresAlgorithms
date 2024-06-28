/*
    You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
    You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
    You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as 
    the sum of the values of the two cities it connects. Return the maximum total importance of all roads possible after assigning the values optimally.

    Example 1:
    Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
    Output: 43
    Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
    - The road (0,1) has an importance of 2 + 4 = 6.
    - The road (1,2) has an importance of 4 + 5 = 9.
    - The road (2,3) has an importance of 5 + 3 = 8.
    - The road (0,2) has an importance of 2 + 5 = 7.
    - The road (1,3) has an importance of 4 + 3 = 7.
    - The road (2,4) has an importance of 5 + 1 = 6.
    The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
    It can be shown that we cannot obtain a greater total importance than 43.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj(n, 0);

        for (auto& road : roads) {
            adj[road[0]]++;
            adj[road[1]]++;
        }

        vector<pair<int, int>> p;
        for (int i = 0; i < n; ++i) 
            p.push_back({adj[i], i});

        sort(p.rbegin(), p.rend());

        vector<int> value(n);
        for (int i = 0; i < n; ++i) 
            value[p[i].second] = n - i;

        long long imp = 0;
        for (auto& road : roads) 
            imp += value[road[0]] + value[road[1]];

        return imp;
    }
};