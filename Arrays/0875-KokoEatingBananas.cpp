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
    int solve(vector<int>& piles, int h, int mid) {
        int ans = 0;

        for(int i=0; i<piles.size(); i++) {
            ans += piles[i]/mid;
            if(piles[i]%mid != 0)
                ans++;
        }

        return ans<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1;
        int hi = piles[piles.size()-1];

        while(l < hi) {
            int m = (l+hi)/2;

            if(solve(piles, h, m))
                hi = m;
            else
                l = m+1;
        }

        return l;
    }
};