/*
    Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). 
    You may return the answer in any order.

    Example 1:
    Input: words = ["bella","label","roller"]
    Output: ["e","l","l"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        vector<int> freq_0(26, 0);
        string s0 = words[0];

        for(int i=0; i<s0.size(); i++) 
            freq_0[s0[i] - 'a']++;

        for(int i=1; i<words.size(); i++) {
            vector<int> freq(26, 0);
            for(int j=0; j<words[i].size(); j++) 
                freq[words[i][j] - 'a']++;
            
            for(int j=0; j<26; j++) 
                freq_0[j] = min(freq_0[j], freq[j]);
        }

        for(int i=0; i<26; i++) {
            for(int j=0; j<freq_0[i]; j++) 
                ans.push_back(string(1, i + 'a'));
        }

        return ans;
    }
};