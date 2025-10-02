/*
    There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and 
    weighted edge between cities fromi and toi, and given the integer distanceThreshold. Return the city with the smallest number of cities that 
    are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the 
    greatest number.

    Example 1:
    Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    Output: 3
    Explanation: The figure above describes the graph. 
    The neighboring cities at a distanceThreshold = 4 for each city are:
    City 0 -> [City 1, City 2] 
    City 1 -> [City 0, City 2, City 3] 
    City 2 -> [City 0, City 1, City 3] 
    City 3 -> [City 1, City 2] 
    Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int i=0; i<n; i++)
            dist[i][i] = 0;

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        for(int city=0; city<n; city++) {
            int cnt = 0;

            for(int adjCity=0; adjCity<n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};