/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You 
    are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
    course bi first if you want to take course ai.
    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.

    Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0. So it is possible.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites) 
            adj[i[0]].push_back(i[1]);
        
        vector<int> indegree(numCourses);
        for(int i=0; i<numCourses; i++) {
            for(auto j : adj[i])
                indegree[j]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        if(topo.size() == numCourses)
            return true;
        return false;
    }
};