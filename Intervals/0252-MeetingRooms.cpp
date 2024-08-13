/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all 
    meetings.

    Example 1:
    Input: [[0,30],[5,10],[15,20]]
    Output: false
*/

#include<bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>> meetings) {
    sort(meetings.begin(), meetings.end());
    
    for(int i=0; i<meetings.size()-1; i++) {
        if(meetings[i][1] >= meetings[i+1][0])
            return false;
    }
    
    return true;
}