/*
    You are given a string s.
    Consider performing the following operation until s becomes empty:
    For every alphabet character from 'a' to 'z', remove the first occurrence of that character in s (if it exists).
    For example, let initially s = "aabcbbca". We do the following operations:
    Remove the underlined characters s = "aabcbbca". The resulting string is s = "abbca".
    Remove the underlined characters s = "abbca". The resulting string is s = "ba".
    Remove the underlined characters s = "ba". The resulting string is s = "".
    Return the value of the string s right before applying the last operation. In the example above, answer is "ba".

    Example 1:
    Input: s = "aabcbbca"
    Output: "ba"
    Explanation: Explained in the statement.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> occu;

        for(auto i : s)
            mp[i]++;
        
        for(int i=0; i<s.size(); i++) 
            occu[s[i]]=i;
        
        int maxi = 0;
        for(auto i : mp) 
            maxi = max(maxi, i.second);
        
        vector<int> ans;
        for(auto i : mp) {
            if(i.second == maxi)
                ans.push_back(i.first);
        }

        vector<pair<int, char>> pq;
        for(auto i: ans) {
            if(occu.find(i) != occu.end());
                pq.push_back({occu[i], i});
        }

        sort(pq.begin(), pq.end());
        string rr = "";
        for(auto i : pq)
            rr += i.second;
        
        return rr;
    }
};