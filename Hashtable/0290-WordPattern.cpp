/*
    Given a pattern and a string s, find if s follows the same pattern.
    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

    Example 1:
    Input: pattern = "abba", s = "dog cat cat dog"
    Output: true

    Example 2:
    Input: pattern = "abba", s = "dog cat cat fish"
    Output: false
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> split(string s) {
        vector<string> splitted;
        string temp = "";
    
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    splitted.push_back(temp);
                    temp = "";
                }
            } else
                temp += c;
        }
        
        if (!temp.empty())
            splitted.push_back(temp);
        
        return splitted;
    }
    
    bool wordPattern(string pattern, string s) {
        vector<string> temp = split(s);
        if(pattern.size() != temp.size()) 
            return false;

        unordered_map<char, string> ansMap;
        unordered_set<string> words;

        for(int i=0;i<pattern.size();i++) {
            char p = pattern[i];
            string word = temp[i];

            if(ansMap.find(p) == ansMap.end()) {
                if(words.find(word) != words.end()) 
                    return false;
                ansMap[p] = word;
                words.insert(word);
            }
            else {
                if(ansMap[p] != word)
                    return false;
            }
        }
        return true;
    }
};