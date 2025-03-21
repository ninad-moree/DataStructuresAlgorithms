/*
    You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name 
    recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, 
    i.e., ingredients[i] may contain a string that is in recipes. You are also given a string array supplies containing all the ingredients that you 
    initially have, and you have an infinite supply of all of them. Return a list of all the recipes that you can create. You may return the answer in 
    any order. Note that two recipes may contain each other in their ingredients.

    Example 1:
    Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    Output: ["bread"]
    Explanation: We can create "bread" since we have the ingredients "yeast" and "flour".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adj;
        unordered_set<string> available(supplies.begin(), supplies .end());
        queue<string> q;

        for(int i=0; i<recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for(auto j : ingredients[i])
                adj[j].push_back(recipes[i]);
        }

        for(auto i : supplies)
            q.push(i);

        vector<string> ans;

        while(!q.empty()) {
            string f = q.front();
            q.pop();

            if(indegree.find(f) != indegree.end())
                ans.push_back(f);

            for(auto r : adj[f]) {
                if(--indegree[r] == 0)
                    q.push(r);
            }
        }

        return ans;
    }
};