/*
    There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities
    ai and bi. The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities,
    it is only counted once. The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities. Given the integer n and the array roads,
    return the maximal network rank of the entire infrastructure.

    Example 1:
    Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
    Output: 4
    Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for(auto i : roads) {
            int x = i[0];
            int y = i[1];

            adj[x].push_back(y);
            adj[y].push_back(x);

            degree[x]++;
            degree[y]++;
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int d1 = degree[i];
            for(int j=i+1; j<n; j++) {
                int d2 = degree[j];

                int total = d1 + d2;

                for(auto neigh : adj[i]) {
                    if(neigh == j)
                        total--;
                }

                ans = max(ans, total);
            }
        }

        return ans;
    }
};