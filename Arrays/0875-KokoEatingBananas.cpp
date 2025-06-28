/*
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile 
    has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to 
    finish eating all the bananas before the guards return. Return the minimum integer k such that she can eat all the bananas within h hours.

    Example 1:
    Input: piles = [3,6,7,11], h = 8
    Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calcHours(vector<int> piles, int mid) {
        long long totalHours = 0;

        for(int i=0; i<piles.size(); i++) {
            if(piles[i] % mid == 0)
                totalHours += (piles[i] / mid);
            else
                totalHours += ((piles[i] / mid) + 1);
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(auto i : piles)
            maxi = max(maxi, i);

        int low = 1;
        int high = maxi;
        int ans = maxi;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long  totalHours = calcHours(piles, mid);

            if(totalHours <= h) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }

        return ans;
    }
};