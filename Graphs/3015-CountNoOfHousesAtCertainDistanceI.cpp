/*
    You are given three positive integers n, x, and y.
    In a city, there exist houses numbered 1 to n connected by n streets. There is a street connecting the house numbered i with the house numbered i + 1 for all 1 <= i <= n - 1 . An additional street connects the house numbered x with the house numbered y.
    For each k, such that 1 <= k <= n, you need to find the number of pairs of houses (house1, house2) such that the minimum number of streets that need to be traveled to reach house2 from house1 is k.
    Return a 1-indexed array result of length n where result[k] represents the total number of pairs of houses such that the minimum streets required to reach one house from the other is k.
    Note that x and y can be equal.

    Input: n = 5, x = 2, y = 4
    Output: [10,8,2,0,0]
    Explanation: For each distance k the pairs are:
    - For k == 1, the pairs are (1, 2), (2, 1), (2, 3), (3, 2), (2, 4), (4, 2), (3, 4), (4, 3), (4, 5), and (5, 4).
    - For k == 2, the pairs are (1, 3), (3, 1), (1, 4), (4, 1), (2, 5), (5, 2), (3, 5), and (5, 3).
    - For k == 3, the pairs are (1, 5), and (5, 1).
    - For k == 4 and k == 5, there are no pairs.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1); 

        for (int i = 1; i < n; i++) {
            int u = i;
            int v = i + 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> ans(n, 0);

        for (int i = 1; i <= n; i++) {
            vector<int> dist(n + 1, -1);
            queue<int> q;
            q.push(i); 
            dist[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        ans[dist[v] - 1]++;
                    }
                }
            }
        }

        return ans;
    }
};