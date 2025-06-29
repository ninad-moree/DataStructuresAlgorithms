/*
    Given a string s, partition it into unique segments according to the following procedure:
    Start building a segment beginning at index 0. Continue extending the current segment character by character until the current segment has not 
    been seen before. Once the segment is unique, add it to your list of segments, mark it as seen, and begin a new segment from the next index.
    Repeat until you reach the end of s. Return an array of strings segments, where segments[i] is the ith segment created.

    Example 1:
    Input: s = "abbccccd"
    Output: ["a","b","bc","c","cc","d"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string str = "";

        for(auto i : s) {
            str += i;
            if(mp.find(str) == mp.end()) {
                mp[str]++;
                ans.push_back(str);
                str = "";
            } 
        }

        return ans;
    }
};