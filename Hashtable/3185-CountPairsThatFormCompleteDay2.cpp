/*
    Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
    A complete day is defined as a time duration that is an exact multiple of 24 hours.
    For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.

    Example 1:
    Input: hours = [12,12,30,24,24]
    Output: 2
    Explanation:
    The pairs of indices that form a complete day are (0, 1) and (3, 4).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long, long long> mp;
        long long ans = 0;
        
        for(auto h : hours) {
            long long rem = h%24;
            long long target = (24 - rem)%24;
            
            if(mp.find(target) != mp.end())
                ans += mp[target];
            mp[rem]++;
        }
        
        return ans;
    }
};