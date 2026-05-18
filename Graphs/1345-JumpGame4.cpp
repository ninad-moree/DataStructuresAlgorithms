/*
    Given an array of integers arr, you are initially positioned at the first index of the array. In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length. i - 1 where: i - 1 >= 0. j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the array. Notice that you can not jump outside of the array at any time.

    Example 1:
    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) 
            return 0;

        unordered_map<int, vector<int>> valToIdx;
        for (int i = 0; i < n; i++)
            valToIdx[arr[i]].push_back(i);

        vector<bool> vis(n, false);
        vis[0] = true;

        queue<int> q;
        q.push(0);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            while (sz--) {
                int x = q.front(); 
                q.pop();

                vector<int> neighbors = {x - 1, x + 1};
                if (valToIdx.count(arr[x])) {
                    for (int j : valToIdx[arr[x]])
                        neighbors.push_back(j);
                    valToIdx.erase(arr[x]);
                }

                for (int nx : neighbors) {
                    if (nx < 0 || nx >= n || vis[nx]) 
                        continue;
                    if (nx == n - 1) 
                        return steps;
                        
                    vis[nx] = true;
                    q.push(nx);
                }
            }
        }

        return -1;
    }
};