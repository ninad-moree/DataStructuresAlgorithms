/*
    You are given a 0-indexed array of strings words and a 2D array of integers queries. Each query queries[i] = [li, ri] asks us to find the 
    number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel. Return an array ans of size 
    queries.length, where ans[i] is the answer to the ith query.

    Example 1:
    Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
    Output: [2,3,0]
    Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
    The answer to the query [0,2] is 2 (strings "aba" and "ece").
    to query [1,4] is 3 (strings "ece", "aa", "e").
    to query [1,1] is 0.
    We return [2,3,0].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;

        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;

        int cnt = 0;
        vector<int> prefix;
        for(auto s : words) {
            if(mp.find(s[0]) != mp.end() && mp.find(s[s.size()-1]) != mp.end())
                cnt++;
            prefix.push_back(cnt);
        }

        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int j = prefix[r];
            int k = l>0 ? prefix[l-1] : 0;

            ans.push_back(j-k);
        }

        return ans;
    }
};