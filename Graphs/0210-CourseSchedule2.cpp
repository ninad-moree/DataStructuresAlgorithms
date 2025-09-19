/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where
    prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai. For example, the pair [0, 1], 
    indicates that to take course 0 you have to first take course 1. Return the ordering of courses you should take to finish all courses.
    If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

    Example 1:
    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 
    and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites) 
            adj[i[1]].push_back(i[0]);
        
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
            return topo;
        return {};
    }
};