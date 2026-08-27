/*
    You are given an integer n representing the number of tasks in a project, numbered from 0 to n - 1. These tasks are connected as a tree rooted at task 0. This is 
    represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that task ui is the parent of task vi. You are also given an array baseTime of 
    length n, where baseTime[i] represents the time to complete task i. The finish time of each task is calculated as follows: Leaf task: The finish time is baseTime[i].
    Non-leaf task: Let earliest be the minimum finish time among its children, and latest be the maximum finish time among its children. Let ownDuration be (latest - earliest) 
    + baseTime[i]. The finish time of task i is latest + ownDuration. Return the finish time of the root task 0.

    Example 1:
    Input: n = 3, edges = [[0,1],[1,2]], baseTime = [9,5,3]
    Output: 17
    Explanation: Task 2 is a leaf, so its finish time is baseTime[2] = 3.
    Task 1 has one child task 2: earliest = latest = 3 ownDuration = (latest - earliest) + baseTime[1] = 5 Finish time of task 1 is 3 + 5 = 8
    Task 0 has one child with finish time 8: earliest = latest = 8 ownDuration = (latest - earliest) + baseTime[0] = 9 Finish time of task 0 is 8 + 9 = 17
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        vector<int> parent(n, -1);
        vector<int> childCnt(n, 0);

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            parent[v] = u;
            childCnt[u]++;
        }
    
        queue<int> q;
        
        // Push Leaf Nodes
        for(int i=0; i<n; i++) {
            if(childCnt[i] == 0)
                q.push(i);
        }
        
        vector<long long> time(n);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // Leaf Node
            if(adj[node].empty())
                time[node] = baseTime[node];

            int par = parent[node];

            if(par != -1) {
                childCnt[par]--;

                if(childCnt[par] == 0)
                    q.push(par);
            }

            if(!adj[node].empty()) {
                long long earliest = LLONG_MAX;
                long long latest = LLONG_MIN;

                for(auto i : adj[node]) {
                    earliest = min(earliest, time[i]);
                    latest = max(latest, time[i]);
                }

                time[node] = latest + (latest - earliest + baseTime[node]);
            }
        }
        
        return time[0];
    }
};