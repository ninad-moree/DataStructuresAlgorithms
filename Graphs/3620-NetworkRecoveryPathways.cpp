/*
    You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array edges of length m, where edges[i] = [ui, vi, costi] indicates a 
    one‑way communication from node ui to node vi with a recovery cost of costi. Some nodes may be offline. You are given a boolean array online where online[i] = true means node
    i is online. Nodes 0 and n − 1 are always online. A path from 0 to n − 1 is valid if: All intermediate nodes on the path are online. The total recovery cost of all edges on 
    the path does not exceed k. For each valid path, define its score as the minimum edge‑cost along that path. Return the maximum path score (i.e., the largest minimum-edge cost)
    among all valid paths. If no valid path exists, return -1.

    Example 1:
    Input: edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [true,true,true,true], k = 10
    Output: 3
    Explanation: The graph has two possible routes from node 0 to node 3: Path 0 → 1 → 3 Total cost = 5 + 10 = 15, which exceeds k (15 > 10), so this path is invalid.
    Path 0 → 2 → 3 Total cost = 3 + 4 = 7 <= k, so this path is valid.The minimum edge‐cost along this path is min(3, 4) = 3.
    There are no other valid paths. Hence, the maximum among all valid path‐scores is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidPath(long long minEdgeCost, vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, long long>>> adj(n);

        for(auto i :edges) {
            int u = i[0];
            int v = i[1];
            int c = i[2];

            if(c < minEdgeCost)
                continue;
            
            if(!online[u] || !online[v])
                continue;

            adj[u].push_back({v, c});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(u == n-1)
                break;

            if(d > dist[u])
                continue;

            for(auto edge : adj[u]) {
                int v = edge.first;
                long long c = edge.second;
                long long nd = d + c;

                if(nd <= k && nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] != LLONG_MAX && dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int m = edges.size();
        if(n == 0 || edges.empty())
            return -1;

        // Collect distinct sorted edge costs to binary search over.
        vector<long long> costs;                
        costs.reserve(edges.size());
        for(auto i : edges)
            costs.push_back(i[2]);

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        int low = 0;
        int high = (int)costs.size() - 1; 
        long long ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(isValidPath(costs[mid], edges, online, k)) {
                ans = costs[mid];
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return (int)ans;
    }
};