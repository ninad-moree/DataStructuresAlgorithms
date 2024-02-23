/*
    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] 
    indicates that there is a flight from city fromi to city toi with cost pricei.
    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is 
    no such route, return -1.

    Example 1:
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
    Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<int> visited (n, INT_MAX);
        visited[src] = 0;

        for(auto i : flights) 
            adj[i[0]].push_back({i[1], i[2]});
        
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        k++;

        while(k--) {
            int s = q.size();
            while(s--) {
                int currPrice = q.front().second;
                for(auto i : adj[q.front().first]) {
                    int newPrice = i.second + currPrice;
                    if(newPrice < visited[i.first]) {
                        visited[i.first] = newPrice;
                        q.push({i.first, newPrice});
                    }
                }
                q.pop();
            }
            cnt++;
        }

        return (visited[dst]==INT_MAX) ? -1 : visited[dst];
    }
};