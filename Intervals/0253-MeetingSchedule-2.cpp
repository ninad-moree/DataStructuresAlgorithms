/*
    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
    find the minimum number of meeting rooms required.

    Example 1:
    Input: intervals = [(0,30),(5,10),(15,20)]
    Output: 2
    Explanation:
    room1: (0,30)
    room2: (5,10),(15,20)
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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) 
            return 0;

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

        return roomsRequired;
    }
};