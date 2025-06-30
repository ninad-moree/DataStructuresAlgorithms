/*
    You are given an integer array bloomDay, an integer m and an integer k. You want to make m bouquets. To make a bouquet, you need to use k 
    adjacent flowers from the garden. The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly 
    one bouquet. Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m 
    bouquets return -1.

    Example 1:
    Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
    Output: 3
    Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
    We need 3 bouquets each should contain 1 flower.
    After day 1: [x, _, _, _, _]   // we can only make one bouquet.
    After day 2: [x, _, _, _, x]   // we can only make two bouquets.
    After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canForm(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt = 0;
        int ans = 0;
        
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) 
                cnt++;
            else {
                ans += (cnt / k);
                cnt = 0;
            }
        }

        ans += (cnt / k);

        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = bloomDay[0];
        int maxi = bloomDay[0];

        for(auto i : bloomDay) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        int low = mini;
        int high = maxi;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            bool isPossible = canForm(bloomDay, mid, m, k);

            if(isPossible) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};