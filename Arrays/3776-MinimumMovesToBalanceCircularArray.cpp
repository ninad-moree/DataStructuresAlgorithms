/*
    You are given a circular array balance of length n, where balance[i] is the net balance of person i. In one move, a person can transfer exactly 1 unit of balance to either 
    their left or right neighbor. Return the minimum number of moves required so that every person has a non-negative balance. If it is impossible, return -1. Note: You are 
    guaranteed that at most 1 index has a negative balance initially.

    Example 1:
    Input: balance = [5,1,-4]
    Output: 4
    Explanation: One optimal sequence of moves is: Move 1 unit from i = 1 to i = 2, resulting in balance = [5, 0, -3], Move 1 unit from i = 0 to i = 2, resulting in balance = 
    [4, 0, -2], Move 1 unit from i = 0 to i = 2, resulting in balance = [3, 0, -1], Move 1 unit from i = 0 to i = 2, resulting in balance = [2, 0, 0]
    Thus, the minimum number of moves required is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long sum = 0;
        int idx = -1;
        vector<pair<int, int>> arr; // {idx, dist from neg idx}

        for(int i=0; i<n; i++) {
            sum += balance[i];

            if(balance[i] < 0) 
                idx = i;
        }

        if(sum < 0)
            return -1;
        
        if(idx == -1) 
            return 0;

        for(int i=0; i<n; i++) {
            if(balance[i] >= 0) {
                int diff = abs(i - idx);
                int mini = min(diff, n - diff);

                arr.push_back({i, mini});
            }
        }

        sort(arr.begin(), arr.end(), [](const auto& a, auto& b) {
            return a.second < b.second;
        });

        long long need = -balance[idx];
        long long ans = 0;

        for(int i=0; i<arr.size(); i++) {
            int in = arr[i].first;
            int dist = arr[i].second;

            long long take = min(need, (long long)balance[in]);

            ans += take * dist;
            need -= take;

            if(need == 0)
                break;
        }

        return ans;
    }
};