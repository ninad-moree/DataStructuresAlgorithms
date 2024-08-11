/*
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    Return any possible rearrangement of s or return "" if not possible.

    Input: s = "aab"
    Output: "aba"   
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(auto& a, auto& b) {
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto i : s)
            mp[i]++;
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        for(auto i : mp)
            pq.push(i);

        string ans = "";

        while(pq.size() > 1) {
            auto curr = pq.top();
            pq.pop();

            auto next = pq.top();
            pq.pop();

            ans += curr.first;
            ans += next.first;

            curr.second--;
            next.second--;

            if(curr.second > 0)
                pq.push(curr);
            if(next.second > 0)
                pq.push(next);
        }

        if(!pq.empty()) {
            if(pq.top().second > 1)
                return "";
            ans += pq.top().first;
        }

        return ans;
    }
};