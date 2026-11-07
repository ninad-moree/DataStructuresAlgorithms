/*
    You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to
    process the j​​​​​​th​​​​ task in seconds. Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty. At second j, the jth task is 
    inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the 
    queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index. If there are no free servers
    and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks 
    from the queue will be assigned in order of insertion following the weight and index priorities above. A server that is assigned task j at second t will be free again at 
    second t + tasks[j]. Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.Return the array ans​​​​.

    Example 1:
    Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
    Output: [2,2,0,2,1,2]
    Explanation: Events in chronological order go as follows:
    - At second 0, task 0 is added and processed using server 2 until second 1.
    - At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
    - At second 2, task 2 is added and processed using server 0 until second 5.
    - At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
    - At second 4, task 4 is added and processed using server 1 until second 5.
    - At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy; // time at which server is free, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle; // weight, idx

        for(int i=0; i<n; i++)
            idle.push({servers[i], i});

        long long time = 0;

        // insert the servers that will become idle at "time" back into idle queue
        auto release = [&]() {
            while(!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();

                idle.push({servers[idx], idx});
            }
        };

        vector<int> ans;
        for(int i=0; i<m; i++) {
            // calculate the current time
            time = max(time, (long long)i);
            release();

            // if no server is idle, time becomes the latest time the server will be idle from the busy queue
            if(idle.empty()) {
                time = busy.top().first;
                release();
            }

            int idx = idle.top().second;
            idle.pop();

            ans.push_back(idx);

            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};