/*
    There are n types of units indexed from 0 to n - 1. You are given a 2D integer array conversions of length n - 1, where conversions[i] = [sourceUniti, targetUniti, 
    conversionFactori]. This indicates that a single unit of type sourceUniti is equivalent to conversionFactori units of type targetUniti. Return an array baseUnitConversion of
    length n, where baseUnitConversion[i] is the number of units of type i equivalent to a single unit of type 0. Since the answer may be large, return each 
    baseUnitConversion[i] modulo 109 + 7.

    Example 1:
    Input: conversions = [[0,1,2],[1,2,3]]
    Output: [1,2,6]
    Explanation: Convert a single unit of type 0 into 2 units of type 1 using conversions[0]. Convert a single unit of type 0 into 6 units of type 2 using conversions[0], then 
    conversions[1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> bfs(int start, int amtStart, vector<vector<pair<int, int>>>& adj, vector<int>& vis) {
        vector<int> ans(adj.size());
        queue<pair<int, long long>> q; // {node, amt}
        q.push({start, amtStart});
        vis[start] = 1;
        ans[start] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            long long amt = q.front().second % MOD;
            q.pop();

            for(auto n : adj[node]) {
                int neigh = n.first;
                long long nextAmt = n.second % MOD;

                if(!vis[neigh]) {
                    // int newAmt = (amt * nextAmt) % MOD;
                    long long newAmt = (1LL * amt * nextAmt) % MOD;
                    ans[neigh] = newAmt;
                    vis[neigh] = 1;
                    q.push({neigh, newAmt});
                }
            }
        }

        return ans;
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size()+1;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n);

        for(auto i : conversions) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        return bfs(0, 1, adj, vis);
    }

    vector<int> baseUnitConversions2(vector<vector<int>>& conversions) {
        int n = conversions.size()+1;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n);

        for(auto i : conversions) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {amt, node}
        pq.push({1, 0});
        vector<int> ans(n, -1);
        ans[0] = 1;

        while(!pq.empty()) {
            int node = pq.top().second;
            long long amt = pq.top().first;
            pq.pop();

            for(auto n : adj[node]) {
                int neigh = n.first;
                long long nextAmt = n.second;
                long long newAmt = (1LL * amt * nextAmt) % MOD;

                if(ans[neigh] == -1) {
                    pq.push({newAmt, neigh});
                    ans[neigh] = newAmt;
                }
            }
        }

        return ans;
    }
};