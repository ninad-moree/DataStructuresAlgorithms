/*
    You are given two 2D integer arrays, items1 and items2, representing two sets of items. Each array items has the following properties:
    items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
    The value of each item in items is unique.
    Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.

    Note: ret should be returned in ascending order by value.

    Example 1:
    Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
    Output: [[1,6],[3,9],[4,5]]
    Explanation: 
    The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
    The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
    The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
    Therefore, we return [[1,6],[3,9],[4,5]].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;

        map<int, int> mp;
        
        for(int i=0;i<items1.size();i++) 
            mp[items1[i][0]] += items1[i][1];
        
        for(int i=0;i<items2.size();i++) 
            mp[items2[i][0]] += items2[i][1];
        

        for(auto i : mp) 
            ans.push_back({i.first, i.second});

        return ans;
    }
};