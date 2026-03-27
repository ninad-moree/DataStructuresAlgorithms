/*
    There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness. You are given an array richer where
    richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are 
    logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time). Return an integer array answer where 
    answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the 
    person x.

    Example 1:
    Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
    Output: [5,5,2,5,4,5,6,7]
    Explanation: 
    answer[0] = 5.
    Person 5 has more money than 3, which has more money than 1, which has more money than 0. The only person who is quieter (has lower quiet[x]) is person 7, but it is not clear
    if they have more money than person 0.
    answer[7] = 7.
    Among all people that definitely have equal to or more money than person 7 (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is 
    person 7. The other answers can be filled out with similar reasoning.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj, vector<int>& ans, vector<int>& quiet) {
        if(ans[src] == -1) {
            ans[src] = src;
            
            for(auto i : adj[src]) {
                int node = dfs(i, adj, ans, quiet);

                if(quiet[node] < quiet[ans[src]])
                    ans[src] = node;
            }
        }

        return ans[src];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);

        vector<vector<int>> adj(n);

        for(auto i : richer) {
            int a = i[0];
            int b = i[1];

            adj[b].push_back(a);
        }

        for(int i=0; i<n; i++)
            dfs(i, adj, ans, quiet);

        return ans;
    }
};