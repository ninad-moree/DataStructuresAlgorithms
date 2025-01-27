/*
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where 
    prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi. For example, the pair [0, 1] indicates 
    that you have to take course 0 before you can take course 1.Prerequisites can also be indirect. If course a is a prerequisite of course b, and 
    course b is a prerequisite of course c, then course a is a prerequisite of course c. You are also given an array queries where queries[j] = 
    [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not. Return a boolean array answer, where 
    answer[j] is the answer to the jth query.

    Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    Output: [false,true]
    Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
    Course 0 is not a prerequisite of course 1, but the opposite is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto e : prerequisites) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++) {
            if(!indegree[i])
                q.push(i);
        }

        unordered_map<int, unordered_set<int>> nodePreq;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto i : adj[node]) {
                nodePreq[i].insert(node);

                for(auto j : nodePreq[node])
                    nodePreq[i].insert(j);

                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
        }

        vector<bool> ans;
        for(auto q : queries)
            ans.push_back(nodePreq[q[1]].count(q[0]) > 0);

        return ans;
    }
};