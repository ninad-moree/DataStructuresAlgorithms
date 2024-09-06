/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto i : strs) {
            string word = i;
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());

            mp[sortedWord].push_back(word);
        }

        vector<vector<string>> ans;

        for(auto i : mp) {
            vector<string> res;
            for(auto j : i.second)
                res.push_back(j);
            ans.push_back(res);
        }

        return ans;
    }
};