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
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        
        for(int i=0; i<hours.size(); i++) {
            for(int j=i+1; j<hours.size(); j++) {
                if((hours[i] + hours[j])%24 == 0)
                    ans++;
            }
        }
        
        return ans;
    }
};