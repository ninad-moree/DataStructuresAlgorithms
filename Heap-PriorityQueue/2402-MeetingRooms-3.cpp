/*
    You are given an integer n. There are n rooms numbered from 0 to n - 1.
    You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during 
    the half-closed time interval [starti, endi). All the values of starti are unique.
    Meetings are allocated to rooms in the following manner:
    Each meeting will take place in the unused room with the lowest number.
    If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the 
    same duration as the original meeting.
    When a room becomes unused, meetings that have an earlier original start time should be given the room.
    Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.
    A half-closed interval [a, b) is the interval between a and b including a and not including b.

    Example 1:
    Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
    Output: 0
    Explanation:
    - At time 0, both rooms are not being used. The first meeting starts in room 0.
    - At time 1, only room 1 is not being used. The second meeting starts in room 1.
    - At time 2, both rooms are being used. The third meeting is delayed.
    - At time 3, both rooms are being used. The fourth meeting is delayed.
    - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
    - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
    Both rooms 0 and 1 held 2 meetings, so we return 0. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;

        for(int i=0;i<n;i++)
            available.push(i);

        sort(meetings.begin(), meetings.end());

        for(auto &&i : meetings) {
            int start = i[0];
            int end = i[1];

            while(busy.size() > 0 && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if(available.size() > 0) {
                int top = available.top();
                rooms[top]++;
                available.pop();
                busy.push({end, top});
            } else {
                auto top = busy.top();
                int end1 = top.first;
                int idx = top.second;

                rooms[idx]++;
                busy.pop();
                busy.push({top.first + end - start, idx});
            }
        }

        // sort(rooms.rbegin(), rooms.rend());
        // return rooms[0];
        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};