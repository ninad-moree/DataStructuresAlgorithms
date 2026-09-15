/*
    You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s. You may delete any number of 
    characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters. Return an integer denoting the minimum total deletion cost 
    required.

    Example 1:
    Input: s = "aabaac", cost = [1,2,3,4,1,10]
    Output: 11
    Explanation:
    Deleting the characters at indices 0, 1, 2, 3, 4 results in the string "c", which consists of equal characters, and the total cost is cost[0] + cost[1] + cost[2] + cost[3] +
    cost[4] = 1 + 2 + 3 + 4 + 1 = 11.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long ans = LLONG_MAX;
        vector<int> vis(26);

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            long long res = 0;
            
            if(!vis[ch - 'a']) {
                vis[ch - 'a'] = 1;

                for(int j=0; j<s.size(); j++) {
                    if(s[j] != ch) 
                        res += cost[j];
                }

                ans = min(ans, res);
            }
        }

        return ans;
    }
};