/*
    You are given an initial list of events, where each event has a unique eventId and a priority. Implement the EventManager class:
    EventManager(int[][] events) Initializes the manager with the given events, where events[i] = [eventIdi, priority​​​​​​​i]. void updatePriority(int eventId, int newPriority) 
    Updates the priority of the active event with id eventId to newPriority. int pollHighest() Removes and returns the eventId of the active event with the highest priority. If
    multiple active events have the same priority, return the smallest eventId among them. If there are no active events, return -1. An event is called active if it has not 
    been removed by pollHighest().

    Example 1:
    Input: ["EventManager", "pollHighest", "updatePriority", "pollHighest", "pollHighest"] [[[[5, 7], [2, 7], [9, 4]]], [], [9, 7], [], []]
    Output: [null, 2, null, 5, 9]
    Explanation
    EventManager eventManager = new EventManager([[5,7], [2,7], [9,4]]); // Initializes the manager with three events
    eventManager.pollHighest(); // both events 5 and 2 have priority 7, so return the smaller id 2. eventManager.updatePriority(9, 7); // event 9 now has priority 7
    eventManager.pollHighest(); // remaining highest priority events are 5 and 9, return 5. eventManager.pollHighest(); // return 9
*/

#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
    }
};

class EventManager {
public:
    vector<vector<int>> events;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> mp;

    EventManager(vector<vector<int>>& events) {
        this->events = events;

        for(auto i : events) {
            int id = i[0];
            int pri = i[1];

            pq.push({pri, id});
            mp[id] = pri;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            int pri = pq.top().first;
            int event = pq.top().second;
            pq.pop();

            if(mp.find(event) != mp.end() && mp[event] == pri) {
                mp.erase(event);
                return event;
            }
        }

        return -1;
    }
};