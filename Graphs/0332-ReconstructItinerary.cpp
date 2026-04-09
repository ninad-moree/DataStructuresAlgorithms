/*
    You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order 
    and return it. All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should 
    return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", 
    "LGB"]. You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

    Example 1:
    Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    Output: ["JFK","MUC","LHR","SFO","SJC"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string start, unordered_map<string, vector<string>>& adj, vector<string>& ans) {
        while(!adj[start].empty()) {
            string next = adj[start].back();
            adj[start].pop_back();
            dfs(next, adj, ans);
        }

        ans.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for(auto i : tickets) 
            adj[i[0]].push_back(i[1]);
        
        for(auto& i : adj)
            sort(i.second.rbegin(), i.second.rend());

        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};