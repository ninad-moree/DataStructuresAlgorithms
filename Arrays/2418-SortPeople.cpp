/*
    You are given an array of strings names, and an array heights that consists of distinct positive 
    integers. Both arrays are of length n. For each index i, names[i] and heights[i] denote the name and 
    height of the ith person. Return names sorted in descending order by the people's heights.

    Example 1:
    Input: names = ["Mary","John","Emma"], heights = [180,165,170]
    Output: ["Mary","Emma","John"]
    Explanation: Mary is the tallest, followed by Emma and John.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> p;
        for(int i=0;i<names.size();i++) 
            p.push_back({heights[i], names[i]});

        sort(p.rbegin(), p.rend());
        
        for(int i=0;i<names.size();i++)
            names[i] = p[i].second;

        return names;
    }
};