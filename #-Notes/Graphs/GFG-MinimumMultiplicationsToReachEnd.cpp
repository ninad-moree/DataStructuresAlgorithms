/*
    Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 
    100000 is done to get the new start. Your task is to find the minimum steps in which end can be achieved starting from start. If it is not 
    possible to reach end, then return -1.

    Example 1:
    Input: arr[] = {2, 5, 7}, start = 3, end = 30
    Output: 2
    Explanation:
    Step 1: 3*2 = 6 % 100000 = 6 
    Step 2: 6*5 = 30 % 100000 = 30
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, INT_MAX);
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;
        
        int MOD = 100000;
        
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            
            int u = f.first;
            int steps = f.second;
            
            for(auto i : arr) {
                int v = (u*i)%MOD;
                
                if(steps+1 < dist[v]) {
                    dist[v] = steps+1;
                    if(v == end)
                        return steps+1;
                    q.push({v, steps+1});
                }
            }
        }
        
        if(start == end)
            return 0;
        return -1;
    }
};