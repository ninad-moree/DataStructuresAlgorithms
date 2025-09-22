/*
    There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you. You are given a list of 
    strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.
    Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If 
    there is no solution, return "". If there are multiple solutions, return any of them.

    Example 1:
    Input: words = ["wrt","wrf","er","ett","rftt"]
    Output: "wertf"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> indegree(V, 0);
        
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) 
                indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        return ans;
    }

    string alienOrder(vector<string>& A) {
        int n = A.size();
        
        vector<vector<int>> adj(26);
        vector<int> present(26, 0);
        
        for (auto &w : A) {
            for (char c : w) 
                present[c-'a'] = 1;
        }

        for(int i=0; i<n-1; i++) {
            string s1 = A[i];
            string s2 = A[i+1];
            

            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) 
                return "";
            
            int len = min(s1.size(), s2.size());
            for(int j=0; j<len; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adj);
        string ans = "";
        
        for(auto i : topo) {
            if(present[i]) 
                ans.push_back(char(i + 'a'));
        }
        
        int countPresent = 0;
        for (int x : present) 
            countPresent += x;
            
        if(ans.size() != countPresent) 
            return "";
        return ans;
    }
};