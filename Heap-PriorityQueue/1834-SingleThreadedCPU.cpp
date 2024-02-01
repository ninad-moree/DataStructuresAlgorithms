/*
    You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] 
    means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.
    You have a single-threaded CPU that can process at most one task at a time and will act in the following way:
    If the CPU is idle and there are no available tasks to process, the CPU remains idle.
    If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have 
    the same shortest processing time, it will choose the task with the smallest index.
    Once a task is started, the CPU will process the entire task without stopping.
    The CPU can finish a task then start a new one instantly.
    Return the order in which the CPU will process the tasks.

    Example 1:
    Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
    Output: [0,2,3,1]
    Explanation: The events go as follows: 
    - At time = 1, task 0 is available to process. Available tasks = {0}.
    - Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
    - At time = 2, task 1 is available to process. Available tasks = {1}.
    - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
    - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
    - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
    - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
    - At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
    - At time = 10, the CPU finishes task 1 and becomes idle.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Task {
        int enqueueTime;
        int processingTime;
        int index;

        Task(int e, int p, int i)  {
            enqueueTime = e; 
            processingTime = p; 
            index = i;        
        }
    };

    struct CompareEnqueueTime {
        bool operator()(const Task& t1, const Task& t2) {
            return t1.enqueueTime > t2.enqueueTime;
        }
    };

    struct Compare {
        bool operator()(const Task& t1, const Task& t2) {
            if (t1.processingTime == t2.processingTime) 
                return t1.index > t2.index;
            return t1.processingTime > t2.processingTime;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
         int n = tasks.size();
        vector<int> order;

        priority_queue<Task, vector<Task>, CompareEnqueueTime> availableTasks;
        priority_queue<Task, vector<Task>, Compare> processingQueue;

        for (int i = 0; i < n; ++i)
            availableTasks.push(Task(tasks[i][0], tasks[i][1], i));

        long long time = 0;
        int processed = 0;
        while (processed < n) {
            while (!availableTasks.empty() && availableTasks.top().enqueueTime <= time) {
                processingQueue.push(availableTasks.top());
                availableTasks.pop();
            }

            if (processingQueue.empty()) {
                time = availableTasks.top().enqueueTime;
                continue;
            }

            Task currentTask = processingQueue.top();
            processingQueue.pop();

            order.push_back(currentTask.index);
            time += currentTask.processingTime;
            processed++;
        }

        return order;
    }
};