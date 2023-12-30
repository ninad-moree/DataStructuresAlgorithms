/*
    You are given an array of strings words (0-indexed).
    In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
    and move any character from words[i] to any position in words[j].
    Return true if you can make every string in words equal using any number of operations, 
    and false otherwise.

    Example 1:

    Input: words = ["abc","aabc","bc"]
    Output: true
    Explanation: Move the first 'a' in words[1] to the front of words[2],
    to make words[1] = "abc" and words[2] = "abc".
    All the strings are now equal to "abc", so return true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int total = 0;
        for(int i=0;i<words.size();i++)
            total += words[i].size();
        
        if(total%n != 0)
            return false;
        
        vector<int> vec(26,0);

        for(int i=0; i<n; i++) {
            string str = words[i];
            for(int j=0;j<str.size();j++) {
                vec[str[j]-'a']++;
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] % n != 0)
                return false;
        }

        return true;
    }
};