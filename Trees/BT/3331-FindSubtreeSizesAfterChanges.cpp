/*
    You are given a tree rooted at node 0 that consists of n nodes numbered from 0 to n - 1. The tree is represented by an array parent of size n, where parent[i] is the parent
    of node i. Since node 0 is the root, parent[0] == -1. You are also given a string s of length n, where s[i] is the character assigned to node i. We make the following 
    changes on the tree one time simultaneously for all nodes x from 1 to n - 1: Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
    If node y does not exist, do nothing. Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.
    Return an array answer of size n where answer[i] is the size of the subtree rooted at node i in the final tree.

    Example 1:
    Input: parent = [-1,0,0,1,1,1], s = "abaabc"
    Output: [6,3,1,1,1,1]
    Explanation: The parent of node 3 will change from node 1 to node 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> newAdj;
    vector<int> ans;
    int last[26]; // closest ancestor of node with ch=c

    // Find new parent of nodes in original tree
    void dfs1(int node, string& s, vector<int>& parent, vector<int>& newParent) {
        int c = s[node] - 'a';
        int saved = last[c];

        if(node != 0 && saved != -1)
            newParent[node] = saved;

        last[c] = node;
        for(auto i : adj[node])
            dfs1(i, s, parent, newParent);
        last[c] = saved;
    }

    // Find tree sizes
    int dfs2(int node) {
        int size = 1;

        for(auto i : newAdj[node])
            size += dfs2(i);

        return ans[node] = size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.assign(n, {});
        newAdj.assign(n, {});
        ans.assign(n, 0);
        
        for(int i=0; i<26; i++)
            last[i] = -1;

        for(int i=1; i<n; i++) {
            int node = i;
            int par = parent[i];

            adj[par].push_back(node);
        }

        vector<int> newParent(parent);
        dfs1(0, s, parent, newParent);

        for(int i=1; i<n; i++) {
            int node = i;
            int par = newParent[i];

            newAdj[par].push_back(node);
        }

        dfs2(0);

        return ans;
    }
};