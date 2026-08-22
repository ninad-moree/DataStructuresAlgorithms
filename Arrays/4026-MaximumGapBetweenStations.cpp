/*
    You are given two strings skill and station of lengths n and m, respectively. skill[i] represents the skill of worker i, and station[j] represents the skill supported by 
    station j. You must assign every worker to a distinct station. Let ji be the index of the station assigned to worker i. A valid assignment must satisfy:
    station[ji] == skill[i] for every 0 <= i < n. The assigned station indices must be strictly increasing in worker order, meaning j0 < j1 < ... < jn - 1. The gap of an 
    assignment is the maximum difference between the station indices assigned to two consecutive workers. In other words, it is max(ji - ji - 1) over all 1 <= i < n.
    If there is only one worker, the gap is 0. Return the maximum possible gap among all valid assignments. It is guaranteed that at least one valid assignment exists.

    Example 1:
    Input: skill = "aa", station = "aaaa"
    Output: 3
    Explanation: The two workers must be assigned to two different 'a' stations. Assigning them to stations [0, 3] gives a gap of 3.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> early(n);
        vector<int> late(n);

        int j = 0;

        for(int i=0; i<n; i++) {
            while(skill[i] != station[j])
                j++;
            
            early[i] = j;
            j++;
        }

        j = m-1;
        for(int i=n-1; i>=0; i--) {
            while(skill[i] != station[j])
                j--;

            late[i] = j;
            j--;
        }

        int ans = 0;
        for(int i=0; i<n-1; i++)
            ans = max(ans, late[i+1] - early[i]);

        return ans;
    }
};