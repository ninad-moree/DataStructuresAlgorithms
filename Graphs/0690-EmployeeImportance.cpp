/*
    You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs. You are given an array of employees 
    employees where: employees[i].id is the ID of the ith employee. employees[i].importance is the importance value of the ith employee. employees[i].subordinates is a list of 
    the IDs of the direct subordinates of the ith employee. Given an integer id that represents an employee's ID, return the total importance value of this employee and all 
    their direct and indirect subordinates.

    Example 1:
    Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
    Output: 11
    Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3. They both have an importance value of 3.
    Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
*/

#include<bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        int n = employees.size();

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> imps;

        for(int i=0; i<n; i++) {
            int id = employees[i]->id;
            int imp = employees[i]->importance;
            vector<int> sub = employees[i]->subordinates;

            for(auto j : sub) 
                adj[id].push_back(j);

            imps[id] = imp;
        }

        queue<int> q;
        q.push(id);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            importance += imps[i];

            for(auto j : adj[i])
                q.push(j);
        }

        return importance;
    }
};