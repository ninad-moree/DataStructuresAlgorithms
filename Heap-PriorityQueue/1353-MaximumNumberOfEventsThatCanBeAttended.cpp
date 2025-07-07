/*
    You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi. You can attend 
    an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d. Return the maximum number of events you 
    can attend.

    Example 1:
    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events. One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int maxi = 0;
        for(auto i : events)
            maxi = max(maxi, i[1]);

        int ans = 0;
        int j = 0;

        for(int i=0; i<=maxi; i++) {
            while(j < events.size() && events[j][0] <= i) {
                pq.push(events[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top() < i)
                pq.pop();

            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};