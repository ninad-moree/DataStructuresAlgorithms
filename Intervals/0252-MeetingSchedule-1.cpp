/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
    determine if a person could attend all meetings.

    Example 1:
    Input: intervals = [(0,30),(5,10),(15,20)]
    Output: false
    Explanation:
    (0,30),(5,10) and (0,30),(15,20) will conflict
*/

#include<bits/stdc++.h>
using namespace std;


class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) 
            return true;

        vector<int> startTimes, endTimes;

        for (const auto& interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int roomsRequired = 0;
        int endIndex = 0;

        for (int i = 0; i < intervals.size(); ++i) {
            if (startTimes[i] < endTimes[endIndex])
                roomsRequired++;
            else
                endIndex++;
        }

        if(roomsRequired > 1)
            return false;
        return true;
    }
};