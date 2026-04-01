/*
    There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of 
    watched videos and the list of friends respectively for the person with id = i. Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched 
    videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given
    your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least
    to greatest. 

    Example 1:
    Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
    Output: ["B","C"] 
    Explanation:  You have id = 0 (green color in the figure) and your friends are (yellow color in the figure): Person with id = 1 -> watchedVideos = ["C"]. 
    Person with id = 2 -> watchedVideos = ["B","C"] 
    The frequencies of watchedVideos by your friends are:  B -> 1 , C -> 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int id, int level, vector<vector<int>>& adj, vector<vector<string>>& watchedVideos, vector<int>& vis, unordered_map<string, int>& mp) {
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        int lvl = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int node = q.front();
                q.pop();

                if(lvl == level) {
                    for(auto i : watchedVideos[node]) 
                        mp[i]++;
                }

                for(auto i : adj[node]) {
                    if(!vis[i]) {
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }

            lvl++;
        }
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<int> vis(n);
        unordered_map<string, int> mp;
        vector<string> ans;

        bfs(id, level, friends, watchedVideos, vis, mp);

        for (auto &it : mp) 
            ans.push_back(it.first);

        sort(ans.begin(), ans.end(), [&](string &a, string &b) {
            if (mp[a] == mp[b])
                return a < b;           
            return mp[a] < mp[b];      
        });

        return ans;
    }
};