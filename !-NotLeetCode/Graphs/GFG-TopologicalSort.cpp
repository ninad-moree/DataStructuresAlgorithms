/*
    Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed 
    edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.
    In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

    Input: [[], [0], [0], [0]]
    Output:
    Explanation:
    The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases.
    One possible Topological order for the graph is 3, 2, 1, 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++) {
	        for(auto j : adj[i]) {
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()) {
	        int f = q.front();
	        q.pop();
	        
	        ans.push_back(f);
	        
	        for(auto i : adj[f]) {
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	      
        return ans;
	}
};