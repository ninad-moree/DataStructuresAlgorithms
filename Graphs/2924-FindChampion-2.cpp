/*
    There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
    You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.
    A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.
    Team a will be the champion of the tournament if there is no team b that is stronger than team a.
    Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.empty()) 
            return 0; 

        unordered_map<int, unordered_set<int>> adjList;
        unordered_set<int> incomingEdges;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].insert(v);
            incomingEdges.insert(v);
        }

        int candidate = -1;
        int incomingCount = 0;

        for (int i = 0; i < n; ++i) {
            if (incomingEdges.find(i) == incomingEdges.end()) {
                candidate = i;
                incomingCount++;
            }
        }

        return incomingCount == 1 ? candidate : -1;
    
    }
};