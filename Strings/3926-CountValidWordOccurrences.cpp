/*
    You are given an array of strings chunks. Concatenate all strings in chunks in order to form a string s. You are also given an array of strings queries.
    A joiner hyphen is a hyphen character '-' in s whose previous and next characters both exist and are lowercase English letters. A word is a maximal substring of s 
    consisting only of lowercase English letters and joiner hyphens. All other characters, including spaces and hyphens that are not joiner hyphens, are treated as separators.
    Return an integer array ans, where ans[i] is the number of times queries[i] appears as a word in s.

    Example 1:
    Input: chunks = ["hello wor","ld hello"], queries = ["hello","world","wor"]
    Output: [2,1,0]
    Explanation: After concatenating all strings in chunks, s = "hello world hello". The words are "hello", "world", and "hello". The substring "wor" appears inside "world", 
    but it is not a full word.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(auto i : chunks)
            s += i;

        vector<string> words;
        string str;

        for(int i=0; i<s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') 
                str += s[i];
            else if (s[i] == '-' && i > 0 && i + 1 < s.size() && s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') 
                str += s[i];
            else {
                if(!str.empty()) {
                    words.push_back(str);
                    str.clear();
                }
            }
        }

        if(!str.empty())
            words.push_back(str);

        unordered_map<string , int> mp;
        for (auto &w : words) 
            mp[w]++;

        vector<int> ans(queries.size());
        
        for(int i=0; i<queries.size(); i++) {
            if(mp.find(queries[i]) != mp.end())
                ans[i] = mp[queries[i]];
        }

        return ans;
    }
};