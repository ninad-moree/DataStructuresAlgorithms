/*
    Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order. A 
    substring is a contiguous sequence of characters within a string

    Example 1:
    Input: words = ["mass","as","hero","superhero"]
    Output: ["as","hero"]
    Explanation: "as" is substring of "mass" and "hero" is substring of "superhero". ["hero","as"] is also a valid answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words.size(); j++) {
                if(words[j].find(words[i]) != string::npos && i != j) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};