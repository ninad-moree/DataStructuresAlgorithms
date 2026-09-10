/*
    You are given two integer arrays costs and capacity, both of length n, where costs[i] represents the purchase cost of the ith machine and capacity[i] represents its 
    performance capacity. You are also given an integer budget. You may select at most two distinct machines such that the total cost of the selected machines is strictly less 
    than budget. Return the maximum achievable total capacity of the selected machines.

    Example 1:
    Input: costs = [4,8,5,3], capacity = [1,5,2,7], budget = 8
    Output: 8
    Explanation: Choose two machines with costs[0] = 4 and costs[3] = 3. The total cost is 4 + 3 = 7, which is strictly less than budget = 8. The maximum total capacity is 
    capacity[0] + capacity[3] = 1 + 7 = 8.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> arr;

        for(int i=0; i<costs.size(); i++) 
            arr.push_back({costs[i], capacity[i]});

        sort(arr.begin(), arr.end());

        vector<int> prefix(n);
        prefix[0] = arr[0].second;

        for(int i=1; i<n; i++)
            prefix[i] = max(prefix[i-1], arr[i].second);

        int ans = 0;

        // Select 1 machine
        for(int i=0; i<n; i++) {
            if(arr[i].first < budget)
                ans = max(ans, arr[i].second);
        }

        // Select 2 machines
        for(int i=0; i<n; i++) {
            int rem = budget - arr[i].first;

            int low = 0;
            int high = i - 1;
            int idx = -1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(arr[mid].first < rem) {
                    idx = mid;
                    low = mid + 1;
                } else
                    high = mid - 1;
            }

            if(idx != -1)
                ans = max(ans, arr[i].second + prefix[idx]);
        }

        return ans;
    }
};