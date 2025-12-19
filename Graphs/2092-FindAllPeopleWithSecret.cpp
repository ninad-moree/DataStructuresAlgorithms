/*
    You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, 
    timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
    Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has
    the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa. The secrets are shared 
    instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame. Return a list of all the people that have 
    the secret after all the meetings have taken place. You may return the answer in any order.

    Example 1:
    Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
    Output: [0,1,2,3,5]
    Explanation: At time 0, person 0 shares the secret with person 1. At time 5, person 1 shares the secret with person 2. At time 8, person 2 shares the secret with person 3.
    At time 10, person 1 shares the secret with person 5.​​​​ Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> visited(n, false);
        visited[firstPerson] = true;
        visited[0] = true;

        map<int, vector<pair<int, int>>> mp;
        for(auto i : meetings)
            mp[i[2]].emplace_back(i[0], i[1]);
        
        for(auto i : mp) {
            unordered_map<int, vector<int>> adjList;
            unordered_set<int> s;

            for(auto j : i.second) {
                int x = j.first;
                int y = j.second;

                adjList[x].push_back(y);
                adjList[y].push_back(x);

                if(visited[x])
                    s.insert(x);
                if(visited[y])
                    s.insert(y);
            }

            queue<int> q;

            for(auto j : s)
                q.push(j);

            while(!q.empty()) {
                auto curr = q.front();
                q.pop();

                for(auto j : adjList[curr]) {
                    if(!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        vector<int> ans; 

        for(int i=0;i<n;i++) {
            if(visited[i])
                ans.push_back(i);
        }

        return ans;
    }
};