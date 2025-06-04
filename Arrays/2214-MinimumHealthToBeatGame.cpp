/*
    You are playing a game that has n levels numbered from 0 to n - 1. You are given a 0-indexed integer array damage where damage[i] is the amount 
    of health you will lose to complete the ith level. You are also given an integer armor. You may use your armor ability at most once during the 
    game on any level which will protect you from at most armor damage. You must complete the levels in order and your health must be greater than 0 
    at all times to beat the game. Return the minimum health you need to start with to beat the game.

    Example 1:
    Input: damage = [2,7,4,3], armor = 4
    Output: 13
    Explanation: One optimal way to beat the game starting at 13 health is:
    On round 1, take 2 damage. You have 13 - 2 = 11 health.
    On round 2, take 7 damage. You have 11 - 7 = 4 health.
    On round 3, use your armor to protect you from 4 damage. You have 4 - 0 = 4 health.
    On round 4, take 3 damage. You have 4 - 3 = 1 health.
    Note that 13 is the minimum health you need to start with to beat the game.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumHealth(vector<int> damage, int armor) {
        sort(damage.rbegin(), damage.rend());
        
        int ans = 1;
        
        for(int i=0; i<damage.size(); i++) {
            if(i == 0) {
                if(damage[i] > armor)
                    ans += (damage[i] - armor);
            } else
                ans += damage[i];
        }
        
        return ans;
    }
};