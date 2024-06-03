/*
    You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). 
    You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i 
    (inclusive). Return the count of days when the employee is available for work but no meetings are scheduled.
    Note: The meetings may overlap.

    Example 1:
    Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
    Output: 2
    Explanation:
    There is no meeting scheduled on the 4th and 8th days.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size() == 0)
            return days;
        
        sort(meetings.begin(), meetings.end());
        
        vector<vector<int>> merge;
        int s = meetings[0][0];
        int e = meetings[0][1];
        
        for(int i=1; i<meetings.size(); i++) {
            if(meetings[i][0] <= e+1)
                e = max(e, meetings[i][1]);
            else {
                merge.push_back({s,e});
                s = meetings[i][0];
                e = meetings[i][1];
            }
        }
        
        merge.push_back({s, e});
        
        int cnt = 0;
        if(merge[0][0] > 1)
            cnt += merge[0][0]-1;
        
        for(int i=1; i<merge.size(); i++) 
            cnt += merge[i][0] - merge[i-1][1] - 1;
        
        if(merge.back()[1] < days)
            cnt += days - merge.back()[1];
        
        return cnt;
    }
};