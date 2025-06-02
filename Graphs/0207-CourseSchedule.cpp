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
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<prerequisites.size(); i++) {
            int e1 = prerequisites[i][0];
            int e2 = prerequisites[i][1];

            indegree[e2]++;
            adj[e1].push_back(e2);
        }

        vector<int> res;
        queue<int> q;

        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        if(q.size() == 0)
            return false;

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            res.push_back(f);

            for(auto i : adj[f]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        if(res.size() != numCourses)
            return false;
        return true;
    }
};