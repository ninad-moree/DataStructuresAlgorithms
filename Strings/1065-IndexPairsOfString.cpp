/*
    Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

    Example 1:
    Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
    Output: [[3,7],[9,13],[10,17]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<pair<int, int>> indexPairs(string s, vector<string> words) {
        vector<pair<int, int>> ans;
        
        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            int n = w.size();
            
            for (int j = 0; j <= s.size() - n; j++) {
                int k = 0;
                
                while (k < n && s[j + k] == w[k])
                    k++;
                
                if (k == n) 
                    ans.push_back({j, j + n - 1});
            }
        }
        
        return ans;
    }
};