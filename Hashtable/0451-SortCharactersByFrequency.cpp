/*
    Given a string s, sort it in decreasing order based on the frequency of the characters. 
    The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.

    Example 1:
    Input: s = "tree"
    Output: "eert"
    Explanation: 'e' appears twice while 'r' and 't' both appear once.
    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++) 
            mp[s[i]]++;
        
        vector<pair<int,char>> vec;
        for(auto val:mp) 
            vec.push_back({val.second,val.first});
        
        sort(vec.begin(),vec.end(), greater<pair<int,char>>());

        string ans;
        for(auto val:vec){
            for(int i=0;i<val.first;i++) 
                ans.push_back(val.second);
        }
        
        return ans;
    }
};