/*
    A sentence is a string of single-space separated words where each word consists only of lowercase letters. A word is uncommon if it appears 
    exactly once in one of the sentences, and does not appear in the other sentence. Given two sentences s1 and s2, return a list of all the 
    uncommon words. You may return the answer in any order.

    Example 1:
    Input: s1 = "this apple is sweet", s2 = "this apple is sour"
    Output: ["sweet","sour"]
    Explanation:
    The word "sweet" appears only in s1, while the word "sour" appears only in s2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> toString(string s) {
        stringstream ss(s);
        string token;

        vector<string> res;

        while(ss >> token) {
            res.push_back(token);
        }

        return res;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        vector<string> v1 = toString(s1);
        vector<string> v2 = toString(s2);

        for(auto i : v1)
            mp[i]++;

        for(auto i : v2)
            mp[i]++;

        vector<string> ans;

        for(auto i : mp) {
            if(i.second == 1)
                ans.push_back(i.first);
        }

        return ans;
    }
};