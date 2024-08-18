/*
    You are given two integer arrays energyDrinkA and energyDrinkB of the same length n by a futuristic sports scientist. These arrays represent the 
    energy boosts per hour provided by two different energy drinks, A and B, respectively. You want to maximize your total energy boost by drinking 
    one energy drink per hour. However, if you want to switch from consuming one energy drink to the other, you need to wait for one hour to cleanse 
    your system (meaning you won't get any energy boost in that hour). Return the maximum total energy boost you can gain in the next n hours.

    Example 1:
    Input: energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]
    Output: 5
    Explanation: To gain an energy boost of 5, drink only the energy drink A (or only B).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        
        if (n == 0) 
            return 0;

        vector<long long> dp1(n, 0), dp2(n, 0);

        dp1[0] = energyDrinkA[0];
        dp2[0] = energyDrinkB[0];

        for (int i = 1; i < n; i++) {
            dp1[i] = energyDrinkA[i] + max(dp1[i-1], (i > 1 ? dp2[i-2] : 0));
            dp2[i] = energyDrinkB[i] + max(dp2[i-1], (i > 1 ? dp1[i-2] : 0));
        }

        return max(dp1[n-1], dp2[n-1]);
    }
};