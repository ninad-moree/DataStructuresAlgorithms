/*
    Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

    Example 1:
    Input: arr = [5,5,4], k = 1
    Output: 1
    Explanation: Remove the single 4, only 5 is left
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int i=0;i<arr.size();i++) 
            mp[arr[i]]++;

        vector<pair<int, int>> vec;

        for(auto i : mp)
            vec.push_back(i);
        
        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            return a.second < b.second;
        });

        int cnt = 0;
        for(auto i : vec) {
            if(k >= i.second) {
                k -= i.second;
                cnt++;
            } else 
                break;
        }

        return vec.size() - cnt;
    }
};